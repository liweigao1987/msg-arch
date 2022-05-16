//
// Created by liweigao on 17-10-26.
//

#ifndef MESSAGE_FRAME_PARTNER_H
#define MESSAGE_FRAME_PARTNER_H

#include "mediator.h"
#include "identifier.h"

class Partner {
public:
    virtual ~Partner() = default;

    virtual void set_mediator(std::shared_ptr<Mediator> mediator) {
        this->_mediator = mediator;
    }

    virtual std::shared_ptr<Mediator> get_mediator() {
        return this->_mediator;
    }

    virtual void set_identifier(std::shared_ptr<Identifier> identifier) {
        this->_identifier = identifier;
    }

    virtual std::shared_ptr<Identifier> get_identifier() {
        return this->_identifier;
    }

protected:
    std::shared_ptr<Mediator> _mediator;
    std::shared_ptr<Identifier> _identifier;
};

#endif //MESSAGE_FRAME_PARTNER_H
