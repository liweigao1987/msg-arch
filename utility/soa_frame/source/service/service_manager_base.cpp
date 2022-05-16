//
// Created by liweigao on 17-11-3.
//

#include "service_manager_base.h"
#include "service_base.h"

std::shared_ptr<ServiceManagerBase> ServiceManagerBase::s_instance;
std::mutex ServiceManagerBase::s_mutex;

std::shared_ptr<ServiceManagerBase> ServiceManagerBase::get_instance() {
    if (s_instance.get() == nullptr) {
        std::lock_guard<std::mutex> lg(s_mutex);
        if (s_instance.get() == nullptr) {
            ServiceManagerBase *smb = new ServiceManagerBase();
            s_instance = std::shared_ptr<ServiceManagerBase>(smb);
        }
    }
    return s_instance;
}

ServiceManagerBase::ServiceManagerBase() {
    this->_services = std::make_shared<std::map<std::shared_ptr<ServiceId>, std::shared_ptr<Service> > >();
}

int ServiceManagerBase::register_service(std::shared_ptr<Service> service) {
    std::shared_ptr<ServiceBase> sb = std::dynamic_pointer_cast<ServiceBase>(service);
    if (sb) {
        std::shared_ptr<ServiceId> id = sb->get_service_id();
        if (!id) {
            id = std::make_shared<ServiceId>();
            std::string uuid = Tools::get_uuid();
            id->set_uuid(uuid);
            sb->set_service_id(id);
        }
        this->_services->emplace(id, sb);
        return 0;
    } else {
        return -1;
    }
}

int ServiceManagerBase::unregister_service(std::shared_ptr<Service> service) {
    std::shared_ptr<ServiceBase> sb = std::dynamic_pointer_cast<ServiceBase>(service);
    if (sb) {
        std::shared_ptr<ServiceId> id = sb->get_service_id();
        this->_services->erase(id);
        return 0;
    } else {
        return -1;
    }
}

std::shared_ptr<Service> ServiceManagerBase::find(std::shared_ptr<ServiceId> id) {
    std::map<std::shared_ptr<ServiceId>, std::shared_ptr<Service> >::iterator it;
    it = _services->find(id);
    if (it != _services->end()) {
        return it->second;
    } else {
        return nullptr;
    }
}