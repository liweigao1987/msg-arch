#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <memory>

#include "sm_processor.h"

int main() {
    std::cout << "---------------   main2 start  ----------------" << std::endl;

    pid_t pid = getpid();
    std::cout << "main2 pid = " << pid << std::endl;
    std::shared_ptr<SmProcessor> processor = std::make_shared<SmProcessor>();
    processor->attach();
    processor->read();
    processor->detach();

    std::cout << "---------------   main2 end    ----------------" << std::endl;
    return 0;
}