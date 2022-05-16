//
// Created by liweigao on 17-11-2.
//

#ifndef MESSAGE_FRAME_PROCESS_TRANSMITTER_H
#define MESSAGE_FRAME_PROCESS_TRANSMITTER_H

#include "transmitter.h"
#include "handle.h"

class ProcessTransmitter : public Transmitter {
public:
    ProcessTransmitter();

    ~ProcessTransmitter();

    int post(std::shared_ptr<Handle> handle);
};

#endif //MESSAGE_FRAME_PROCESS_TRANSMITTER_H
