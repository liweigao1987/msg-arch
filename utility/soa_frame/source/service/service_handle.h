//
// Created by liweigao on 17-11-6.
//

#ifndef MESSAGE_FRAME_SERVICEHANDLE_H
#define MESSAGE_FRAME_SERVICEHANDLE_H

#include <set>

#include "handle.h"

class ServiceHandle {
public:
    ServiceHandle() {
        _service_ids = std::make_shared<std::set<std::shared_ptr<ServiceId> > >();
    }

    int add_service_id(std::shared_ptr<ServiceId> id) {
        _service_ids->emplace(id);
        return 0;
    }

    int delete_service_id(std::shared_ptr<ServiceId> id) {
        _service_ids->erase(id);
        return 0;
    }

    void set_service_ids(std::shared_ptr<std::set<std::shared_ptr<ServiceId> > > service_ids) {
        this->_service_ids = service_ids;
    }

    std::shared_ptr<std::set<std::shared_ptr<ServiceId> > > get_service_ids() {
        return this->_service_ids;
    }

    void set_message_handle(std::shared_ptr<Handle> handle) {
        this->_handle = handle;
    }

    std::shared_ptr<Handle> get_message_handle() {
        return this->_handle;
    }

    template <typename Any>
    int set_Any(Any any) {
        std::shared_ptr<Handle> handle = lazy_get_Handle();
        return handle->set_any<Any>(any);
    }

    int set_transmitter_type(int type) {
        std::shared_ptr<Handle> handle = lazy_get_Handle();
        return handle->set_transmitter_type(type);
    }

    std::shared_ptr<Handle> lazy_get_Handle() {
        if (!_handle) {
            _handle = std::make_shared<Handle>();
        }
        return _handle;
    }

protected:
    std::shared_ptr<Handle> _handle;
    std::shared_ptr<std::set<std::shared_ptr<ServiceId> > > _service_ids;
};

#endif //MESSAGE_FRAME_SERVICEHANDLE_H
