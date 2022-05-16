#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <thread>
#include <string>
#include <exception>

#include "handle.h"
#include "identifier.h"
#include "mediator.h"
#include "mediator_base.h"
#include "partner.h"
#include "partner_manager.h"
#include "partner_manager_base.h"
#include "message_base.h"
#include "content_base.h"



bool g_is_interrupted = false;
void signal_handler(int signal) {
    std::cout << "signal = " << signal << std::endl;
    if (signal == SIGINT) {
        g_is_interrupted = true;
    }
}

template <typename Any>
int send(std::shared_ptr<PartnerBase> sender, std::shared_ptr<PartnerBase> receiver, Any any) {
    std::shared_ptr<Handle> handle = std::make_shared<Handle>();
    handle->set_receiver_id(receiver->get_identifier());
    handle->set_any<Any>(any);
    handle->set_transmitter_type(1);
    sender->send(handle);
}

int main() {
    std::cout << "---------------   main start  ----------------" << std::endl;
    sighandler_t status = signal(SIGINT, signal_handler);

    std::shared_ptr<PartnerBase> sender = std::make_shared<PartnerBase>();
    std::shared_ptr<PartnerBase> receiver = std::make_shared<PartnerBase>();
    std::shared_ptr<Mediator> mediator = std::make_shared<MediatorBase>();
    sender->set_mediator(mediator);
    receiver->set_mediator(mediator);
    std::shared_ptr<PartnerManager> partner_manager = PartnerManagerBase::get_instance();
    partner_manager->register_partner(receiver);
    partner_manager->register_partner(sender);
    send<std::string>(sender, receiver, "lwg");
    send<int>(sender, receiver, 6);
    std::shared_ptr<std::vector<int> > vec = std::make_shared<std::vector<int> >();
    vec->push_back(2);
    vec->push_back(3);
    send<std::shared_ptr<std::vector<int> > >(sender, receiver, vec);

    while(!g_is_interrupted) {
        sleep(1);
    }
    std::cout << "---------------   main end    ----------------" << std::endl;
    return 0;
}