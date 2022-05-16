//
// Created by liweigao on 17-10-26.
//

#ifndef MESSAGE_FRAME_MESSAGE_BASE_H
#define MESSAGE_FRAME_MESSAGE_BASE_H

#include <string>
#include <memory>

#include "message.h"
#include "identifier.h"
#include "content.h"
#include "content_base.h"

class MessageBase : public Message {
public:
    MessageBase() : _transmitter_type(0) {

    }

    virtual void set_priority(int priority) {
        this->_priority = priority;
    }

    virtual int get_priority() {
        return this->_priority;
    }

    virtual void set_sequence_number(std::string sn) {
        this->_sequence_number = sn;
    }

    virtual std::string get_sequence_number() {
        return this->_sequence_number;
    }

    virtual int set_sender_id(std::shared_ptr<Identifier> id) {
        this->_sender_id = id;
        return 0;
    }

    virtual std::shared_ptr<Identifier> get_sender_id() {
        return this->_sender_id;
    }

    virtual int set_receiver_id(std::shared_ptr<Identifier> id) {
        this->_receiver_id = id;
        return 0;
    }

    virtual std::shared_ptr<Identifier> get_receiver_id() {
        return this->_receiver_id;
    }

    virtual void set_content(std::shared_ptr<Content> content) {
        this->_content = content;
    }

    virtual std::shared_ptr<Content> get_content() {
        return this->_content;
    }

    template <typename Any>
    std::shared_ptr<ContentBase<Any> > get_content_base() {
        return std::dynamic_pointer_cast<ContentBase<Any> >(_content);
    }

    template <typename Any>
    int set_any(Any any) {
        if (!_content) {
            _content = std::make_shared<ContentBase<Any> >();
        }
        std::shared_ptr<ContentBase<Any> > cb = get_content_base<Any>();
        if (cb) {
            return cb->set_any(any);
        } else {
            return -1;
        }
    }

    std::string to_string() {
        return _content->to_string();
    }

    int set_transmitter_type(int type) {
        this->_transmitter_type = type;
    }

    int get_transmitter_type() {
        return this->_transmitter_type;
    }

private:
    int _priority;
    int _transmitter_type;
    std::string _sequence_number;
    std::shared_ptr<Identifier> _sender_id;
    std::shared_ptr<Identifier> _receiver_id;
    std::shared_ptr<Content> _content;
};

#endif //MESSAGE_FRAME_MESSAGE_BASE_H
