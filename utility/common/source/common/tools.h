//
// Created by liweigao on 17-11-1.
//

#ifndef MESSAGE_FRAME_TOOLS_H
#define MESSAGE_FRAME_TOOLS_H

#include <string>
#include <uuid/uuid.h>
#include <sstream>

class Tools {
public:
    static std::string get_uuid() {
        uuid_t id;
        uuid_generate(id);
        return cast<uuid_t, std::string>(id);
    }

    template <typename from_type, typename to_type>
    static to_type cast(from_type src) {
        std::ostringstream oss;
        oss << src;
        return oss.str();
//        std::stringstream ss;
//        ss << src;
//        to_type dst;
//        ss >> dst;
//        return dst;
    }
};

#endif //MESSAGE_FRAME_TOOLS_H
