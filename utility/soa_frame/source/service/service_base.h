//
// Created by liweigao on 17-11-3.
//

#ifndef MESSAGE_FRAME_SERVICE_BASE_H
#define MESSAGE_FRAME_SERVICE_BASE_H

#include "service.h"
#include "service_id.h"
#include "partner_base.h"

class ServiceBase : public Service {
public:
    void set_service_id(std::shared_ptr<ServiceId> id) {
        this->_service_id = id;
    }

    std::shared_ptr<ServiceId> get_service_id() {
        return this->_service_id;
    }

    void set_partner(std::shared_ptr<PartnerBase> partner) {
        this->_partner = partner;
    }

    std::shared_ptr<PartnerBase> get_partner() {
        return this->_partner;
    }

protected:
    std::shared_ptr<ServiceId> _service_id;
    std::shared_ptr<PartnerBase> _partner;
};

#endif //MESSAGE_FRAME_SERVICE_BASE_H
