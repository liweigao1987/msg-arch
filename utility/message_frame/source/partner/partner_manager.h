//
// Created by liweigao on 17-10-30.
//

#ifndef MESSAGE_FRAME_PARTNER_MANAGER_H
#define MESSAGE_FRAME_PARTNER_MANAGER_H

#include <memory>

#include "partner.h"
#include "partner_base.h"
#include "identifier.h"

class PartnerManager {
public:
    virtual ~PartnerManager() = default;

    virtual int register_partner(std::shared_ptr<Partner> partner) = 0;

    virtual int unregister_partner(std::shared_ptr<Partner> partner) = 0;

    virtual std::shared_ptr<Partner> find(std::shared_ptr<Identifier> identifier) = 0;

    virtual std::shared_ptr<PartnerBase> find_partner_base(std::shared_ptr<Identifier> identifier) = 0;

};

#endif //MESSAGE_FRAME_PARTNER_MANAGER_H
