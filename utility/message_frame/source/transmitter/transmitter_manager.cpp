//
// Created by liweigao on 17-10-30.
//

#include "transmitter_manager.h"
#include "thread_transmitter.h"
#include "process_transmitter.h"

TransmitterManager::TransmitterManager() {
    this->_transmitters = std::make_shared<std::map<int, std::shared_ptr<Transmitter> > >();
    std::shared_ptr<Transmitter> thread_transmitter = std::make_shared<ThreadTransmitter>();
    this->_transmitters->emplace(1, thread_transmitter);
    std::shared_ptr<Transmitter> process_transmitter = std::make_shared<ProcessTransmitter>();
    this->_transmitters->emplace(2, process_transmitter);
}

int TransmitterManager::post(std::shared_ptr<Handle> handle) {
    std::shared_ptr<Transmitter> transmitter = get_transmitter(handle);
    if (transmitter) {
        return transmitter->post(handle);
    } else {
        -1;
    }
}

std::shared_ptr<Transmitter> TransmitterManager::get_transmitter(std::shared_ptr<Handle> handle) {
    if (handle) {
        std::shared_ptr<MessageBase> mb = handle->get_message_base();
        if (mb) {
            int transmitter_type = mb->get_transmitter_type();
            std::map<int, std::shared_ptr<Transmitter> >::iterator it = _transmitters->find(transmitter_type);
            if (it != _transmitters->end()) {
                return it->second;
            }
        }
    }
    return nullptr;
}
