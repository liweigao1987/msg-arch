//
// Created by liweigao on 17-10-26.
//

#ifndef MESSAGE_FRAME_TRANSMITTER_H
#define MESSAGE_FRAME_TRANSMITTER_H

#include "handle.h"

class Transmitter {
public:
    virtual ~Transmitter() = default;

    virtual int post(std::shared_ptr<Handle> handle) = 0;
};

#endif //MESSAGE_FRAME_TRANSMITTER_H
