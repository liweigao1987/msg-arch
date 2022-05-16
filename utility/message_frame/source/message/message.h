#ifndef MESSAGE_H
#define MESSAGE_H

class Message {

public:
    virtual ~Message() = default;

    virtual std::string to_string() {}
};

#endif