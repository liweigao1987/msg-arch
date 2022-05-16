//
// Created by liweigao on 17-11-5.
//

#ifndef MESSAGE_FRAME_SERVICE_ID_H
#define MESSAGE_FRAME_SERVICE_ID_H

#include <string>
#include <memory>

#include "identifier.h"

class ServiceId {
public:
    bool operator==(ServiceId &rid) {
        if (this == &rid) {
            return true;
        } else {
            if (get_unique_id() == rid.get_unique_id()) {
                return true;
            } else {
                return false;
            }
        }
    }

    std::string get_unique_id() {
        return get_uuid();
    }

    void set_uuid(std::string uuid) {
        this->_uuid = uuid;
    }

    std::string get_uuid() {
        return this->_uuid;
    }

    int set_partner_id(std::shared_ptr<Identifier> id) {
        this->_partner_id = id;
        return 0;
    }

    std::shared_ptr<Identifier> get_partner_id() {
        return this->_partner_id;
    }

protected:
    std::string _uuid;
    std::shared_ptr<Identifier> _partner_id;
};

#endif //MESSAGE_FRAME_SERVICE_ID_H
