#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <thread>
#include <string>
#include <exception>

#include "simple_service.h"
#include "service_handle.h"

bool g_is_interrupted = false;
void signal_handler(int signal) {
    std::cout << "signal = " << signal << std::endl;
    if (signal == SIGINT) {
        g_is_interrupted = true;
    }
}

template <typename Any>
void post(std::shared_ptr<SimpleService> from, std::shared_ptr<SimpleService> to, Any any) {
    std::shared_ptr<ServiceHandle> sh = std::make_shared<ServiceHandle>();
    sh->add_service_id(to->get_service_id());
    sh->set_Any<Any>(any);
    sh->set_transmitter_type(1);
    from->post(sh);
}

int main() {
    std::cout << "---------------   main start  ----------------" << std::endl;
    sighandler_t status = signal(SIGINT, signal_handler);

    std::shared_ptr<SimpleService> ss1 = std::make_shared<SimpleService>();
    std::cout << "ss1=" << ss1->get_partner() << std::endl;
    std::shared_ptr<SimpleService> ss2 = std::make_shared<SimpleService>();
    std::cout << "ss2=" << ss2->get_partner() << std::endl;
    post<std::string>(ss1, ss2, "service test");
    post<int>(ss1, ss2, 46);

    while(!g_is_interrupted) {
        sleep(1);
    }
    std::cout << "---------------   main end    ----------------" << std::endl;
    return 0;
}