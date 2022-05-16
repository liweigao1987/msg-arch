//
// Created by liweigao on 17-11-10.
//

#ifndef RPC_FRAME_SM_MANAGER_H
#define RPC_FRAME_SM_MANAGER_H

#include <sys/shm.h>

#include "sm_data.h"

class SmManager {
public:
    SmManager() {
        _key = 777;
        _handle = -1;
    }

    int get_handle() {
        return this->_handle;
    }

    key_t get_key() {
        return this->_key;
    }

    int create_sm() {
        size_t length = sizeof(struct SmData);
        this->_handle = shmget(_key, length, 0666|IPC_CREAT);
        return _handle;
    }

private:
    int _handle;
    key_t _key;
};

#endif //RPC_FRAME_SM_MANAGER_H
