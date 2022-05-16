#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <memory>
#include <sys/msg.h>

#include "msg_data.h"

int main() {
    std::cout << "---------------   main6 start  ----------------" << std::endl;

    pid_t pid = getpid();
    std::cout << "main4 pid = " << pid << std::endl;
    int q_id = -1;
    q_id = msgget(1234, 0666|IPC_CREAT);
    struct MsgData msg;
    msgrcv(q_id, &msg, 4096, 0, 0);
    std::cout << "msgrcv = " << msg.data << std::endl;

    struct MsgData msg1;
    msgrcv(q_id, &msg1, 4096, 0, 0);
    std::cout << "msgrcv1 = " << msg1.data << std::endl;

    std::cout << "---------------   main6 end    ----------------" << std::endl;
    return 0;
}