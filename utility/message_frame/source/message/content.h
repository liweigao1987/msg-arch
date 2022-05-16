//
// Created by liweigao on 17-11-2.
//

#ifndef MESSAGE_FRAME_CONTENT_H
#define MESSAGE_FRAME_CONTENT_H

class Content {

public:
    virtual ~Content() = default;

    virtual std::string to_string() {}
};

#endif //MESSAGE_FRAME_CONTENT_H
