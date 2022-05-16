//
// Created by liweigao on 17-11-18.
//

#ifndef RPC_FRAME_MSG_DATA_H
#define RPC_FRAME_MSG_DATA_H

struct MsgData {
    long int _msg_type;
    char data[4096];
};

#endif //RPC_FRAME_MSG_DATA_H
