#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <memory>
#include <sys/socket.h>

#include "msg_data.h"

int main() {
    std::cout << "---------------   main5 start  ----------------" << std::endl;

    pid_t pid = getpid();
    std::cout << "main5 pid = " << pid << std::endl;

    int sfd = socket(AF_LOCAL, SOCK_STREAM, 0);


    std::cout << "---------------   main5 end    ----------------" << std::endl;
    return 0;
}