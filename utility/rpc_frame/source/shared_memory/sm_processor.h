//
// Created by liweigao on 17-11-10.
//

#ifndef RPC_FRAME_SM_PROCESSOR_H
#define RPC_FRAME_SM_PROCESSOR_H

#include <memory>
#include <cstring>
#include <iostream>
#include <vector>

#include "sm_data.h"
#include "sm_manager.h"

class SmProcessor {
public:
    SmProcessor() {
        _manager = new SmManager();
        _manager->create_sm();
    }

    ~SmProcessor() {
        delete _manager;
    }

    void attach() {
        int handle = _manager->get_handle();
        _sm_addr = shmat(handle, nullptr, 0);
        _data = (struct SmData *)_sm_addr;
    }

    void read() {
        if (_data->written == 0) {
            char *data = new char[4096];
            memcpy(data, _data->text, 4096);
            std::shared_ptr<std::vector<char> > vec =
                    std::make_shared<std::vector<char> >
                            (data, data + sizeof(data) / sizeof(char));
            std::cout << "read data=" << data << std::endl;
        }

    }

    void write() {
        char *data = "lwg test";
        int len = strlen(data) + 1;
        strncpy(_data->text, data, len);
        _data->written = 1;
    }

    void detach() {
        if (shmdt(_sm_addr) == -1) {
            std::cout << "shmdt failed" << std::endl;
        }
    }

private:
    void *_sm_addr;
    SmManager *_manager;
    struct SmData *_data;
};

#endif //RPC_FRAME_SM_PROCESSOR_H
