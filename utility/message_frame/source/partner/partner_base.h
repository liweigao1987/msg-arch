//
// Created by liweigao on 17-11-8.
//

#ifndef MESSAGE_FRAME_PARTNER_BASE_H
#define MESSAGE_FRAME_PARTNER_BASE_H

#include "partner.h"
#include "handle.h"

class PartnerBase : public Partner {
public:
    virtual ~PartnerBase() = default;

    virtual int send(std::shared_ptr<Handle> handle);

    virtual int receive(std::shared_ptr<Handle> handle);
};

#endif //MESSAGE_FRAME_PARTNER_BASE_H
