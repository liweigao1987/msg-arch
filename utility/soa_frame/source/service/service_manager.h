//
// Created by liweigao on 17-11-3.
//

#ifndef MESSAGE_FRAME_SERVICE_MANAGER_H
#define MESSAGE_FRAME_SERVICE_MANAGER_H

#include <memory>

#include "service.h"
#include "service_id.h"

class ServiceManager {
public:
    virtual ~ServiceManager() = default;

    virtual int register_service(std::shared_ptr<Service> service) = 0;

    virtual int unregister_service(std::shared_ptr<Service> service) = 0;

    virtual std::shared_ptr<Service> find(std::shared_ptr<ServiceId> id) = 0;
};

#endif //MESSAGE_FRAME_SERVICE_MANAGER_H
