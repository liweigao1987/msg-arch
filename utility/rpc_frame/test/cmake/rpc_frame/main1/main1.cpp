#include <iostream>
#include <unistd.h>
#include <memory>

#include "sm_data.h"
#include "sm_manager.h"
#include "sm_processor.h"

int main() {
    std::cout << "---------------   main1 start  ----------------" << std::endl;

    pid_t pid = getpid();
    std::cout << "main1 pid = " << pid << std::endl;
    std::shared_ptr<SmProcessor> processor = std::make_shared<SmProcessor>();
    processor->attach();
    processor->write();
    processor->detach();

    std::cout << "---------------   main1 end    ----------------" << std::endl;
    return 0;
}