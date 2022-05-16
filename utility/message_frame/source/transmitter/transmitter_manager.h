//
// Created by liweigao on 17-10-30.
//

#ifndef MESSAGE_FRAME_TRANSMITTER_MANAGER_H
#define MESSAGE_FRAME_TRANSMITTER_MANAGER_H

#include <memory>
#include <map>

#include "handle.h"
#include "transmitter.h"

class TransmitterManager {

public:
    TransmitterManager();

    int post(std::shared_ptr<Handle> handle);

private:
    std::shared_ptr<Transmitter> get_transmitter(std::shared_ptr<Handle> handle);

    std::shared_ptr<std::map<int, std::shared_ptr<Transmitter> > > _transmitters;

};

#endif //MESSAGE_FRAME_TRANSMITTER_MANAGER_H
