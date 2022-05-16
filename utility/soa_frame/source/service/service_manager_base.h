//
// Created by liweigao on 17-11-3.
//

#ifndef MESSAGE_FRAME_SERVICE_MANAGER_BASE_H
#define MESSAGE_FRAME_SERVICE_MANAGER_BASE_H

#include <map>
#include <memory>
#include <mutex>

#include "service_manager.h"

class ServiceManagerBase : public ServiceManager {
public:
    static std::shared_ptr<ServiceManagerBase> get_instance();

    virtual ~ServiceManagerBase() = default;

    virtual int register_service(std::shared_ptr<Service> service);

    virtual int unregister_service(std::shared_ptr<Service> service);

    virtual std::shared_ptr<Service> find(std::shared_ptr<ServiceId> id);

protected:
    std::shared_ptr<std::map<std::shared_ptr<ServiceId>, std::shared_ptr<Service> > > _services;

private:
    static std::shared_ptr<ServiceManagerBase> s_instance;
    static std::mutex s_mutex;

    ServiceManagerBase();
};

#endif //MESSAGE_FRAME_SERVICE_MANAGER_BASE_H
