//
// Created by liweigao on 17-10-26.
//

#ifndef MESSAGE_FRAME_IDENTIFIER_H
#define MESSAGE_FRAME_IDENTIFIER_H

class Identifier {
public:
    virtual ~Identifier() = default;

    virtual bool operator==(Identifier &id) {
        if (this == &id) {
            return true;
        } else {
            std::string r_id = id.get_unique_id();
            if (_uuid == r_id) {
                return true;
            } else {
                return false;
            }
        }
    }

    virtual std::string get_unique_id() {
        return this->_uuid;
    }

    void set_uuid(std::string uuid) {
        this->_uuid = uuid;
    }

    std::string get_uuid() {
        return this->_uuid;
    }

protected:
    std::string _uuid;
};

#endif //MESSAGE_FRAME_IDENTIFIER_H
