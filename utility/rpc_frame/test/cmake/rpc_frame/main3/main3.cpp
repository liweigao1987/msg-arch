#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <memory>
#include <sys/msg.h>
#include <cstring>

#include "msg_data.h"

int main() {
    std::cout << "---------------   main3 start  ----------------" << std::endl;

    pid_t pid = getpid();
    std::cout << "main3 pid = " << pid << std::endl;
    int q_id = -1;
    key_t key = 1234;
    q_id = msgget(key, 0666|IPC_CREAT);
    struct MsgData msg;
    msg._msg_type = 1;
    char *temp = "lwg test";
    memcpy(msg.data, temp, strlen(temp));
    msgsnd(q_id, &msg, sizeof(msg.data), 0);

    struct MsgData msg1;
    msg1._msg_type = 1;
    char *temp1 = "lwg test11";
    memcpy(msg1.data, temp1, strlen(temp1));
    msgsnd(q_id, &msg1, sizeof(msg1.data), 0);

    std::cout << "---------------   main3 end    ----------------" << std::endl;
    return 0;
}