//
// Created by liweigao on 17-11-2.
//

#ifndef MESSAGE_FRAME_CONTENT_BASE_H
#define MESSAGE_FRAME_CONTENT_BASE_H

#include "content.h"
#include "tools.h"

template <typename Any>
class ContentBase : public Content {
public:
    int set_any(Any any) {
        this->_any = any;
        return 0;
    }

    Any get_any() {
        return this->_any;
    }

    std::string to_string() {
        return Tools::cast<Any, std::string>(_any);
    }

private:
    Any _any;
};

#endif //MESSAGE_FRAME_CONTENT_BASE_H
