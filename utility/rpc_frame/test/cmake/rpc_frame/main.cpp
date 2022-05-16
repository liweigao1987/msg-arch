#include <iostream>
#include <signal.h>
#include <unistd.h>

bool g_is_interrupted = false;
void signal_handler(int signal) {
    std::cout << "signal = " << signal << std::endl;
    if (signal == SIGINT) {
        g_is_interrupted = true;
    }
}

int main() {
    std::cout << "---------------   main start  ----------------" << std::endl;
    sighandler_t status = signal(SIGINT, signal_handler);

    pid_t w_id = fork();
    if (w_id < 0) {
        std::cout << "w_id < 0" << std::endl;
    } else if (w_id == 0) {
        std::cout << "w_id == 0" << std::endl;
        int ret = execl("main5/main5", NULL);
        std::cout << "execl ret1 = " << ret << std::endl;
    } else {
        std::cout << "w_id > 0" << std::endl;
        pid_t pid2 = fork();
        if (pid2 < 0) {
            std::cout << "pid2 < 0" << std::endl;
        } else if (pid2 == 0) {
            std::cout << "pid2 == 0" << std::endl;
            int ret = execl("main6/main6", NULL);
            std::cout << "execl ret2 = " << ret << std::endl;
        } else {
            std::cout << "pid2 > 0" << std::endl;
        }
    }

    pid_t current_pid = getpid();
    std::cout << "current pid = " << current_pid << std::endl;
    std::cout << "pid = " << w_id << std::endl;

    while(!g_is_interrupted) {
        sleep(1);
    }
    std::cout << "---------------   main end    ----------------" << std::endl;
    return 0;
}