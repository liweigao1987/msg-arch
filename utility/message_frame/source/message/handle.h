#ifndef HANDLE_H
#define HANDLE_H

#include <string>
#include <memory>

#include "message.h"
#include "message_base.h"
#include "content.h"
#include "content_base.h"
#include "identifier.h"

class Handle {
public:
    void set_message(std::shared_ptr<Message> message) {
        this->_message = message;
    }

    std::shared_ptr<Message> get_message() {
        return this->_message;
    }

    std::shared_ptr<MessageBase> get_message_base() {
        return std::dynamic_pointer_cast<MessageBase>(_message);
    }

    std::shared_ptr<Content> get_content() {
        std::shared_ptr<MessageBase> mb = get_message_base();
        return mb->get_content();
    }

    template <typename Any>
    std::shared_ptr<ContentBase<Any> > get_content_base() {
        std::shared_ptr<MessageBase> mb = get_message_base();
        return mb->get_content_base<Any>();
    }

    std::shared_ptr<Identifier> get_receiver_id() {
        std::shared_ptr<MessageBase> mb = get_message_base();
        return mb->get_receiver_id();
    }

    std::shared_ptr<Identifier> get_sender_id() {
        std::shared_ptr<MessageBase> mb = get_message_base();
        return mb->get_sender_id();
    }

    std::string to_string() {
        return _message->to_string();
    }

    template <typename Any>
    int set_any(Any any) {
        std::shared_ptr<MessageBase> mb = lazy_get_message_base();
        if (mb) {
            return mb->set_any<Any>(any);
        } else {
            return -1;
        }
    }

    int set_receiver_id(std::shared_ptr<Identifier> id) {
        std::shared_ptr<MessageBase> mb = lazy_get_message_base();
        if (mb) {
            return mb->set_receiver_id(id);
        } else {
            return -1;
        }
    }

    int set_sender_id(std::shared_ptr<Identifier> id) {
        std::shared_ptr<MessageBase> mb = lazy_get_message_base();
        if (mb) {
            return mb->set_sender_id(id);
        } else {
            return -1;
        }
    }

    std::shared_ptr<MessageBase> lazy_get_message_base() {
        if (!_message) {
            _message = std::make_shared<MessageBase>();
        }
        return get_message_base();
    }

    int set_transmitter_type(int type) {
        std::shared_ptr<MessageBase> mb = get_message_base();
        if (mb) {
            mb->set_transmitter_type(type);
            return 0;
        } else {
            return -1;
        }
    }

private:
    std::shared_ptr<Message> _message;
};

#endif