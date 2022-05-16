//
// Created by liweigao on 17-10-30.
//

#ifndef MESSAGE_FRAME_THREAD_TRANSMITTER_H
#define MESSAGE_FRAME_THREAD_TRANSMITTER_H

#include "transmitter.h"
#include "handle.h"

class ThreadTransmitter : public Transmitter {
public:
    ThreadTransmitter();

    int post(std::shared_ptr<Handle> handle);
};

#endif //MESSAGE_FRAME_THREAD_TRANSMITTER_H
