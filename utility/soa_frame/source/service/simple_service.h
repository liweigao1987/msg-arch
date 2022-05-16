//
// Created by liweigao on 17-11-6.
//

#ifndef MESSAGE_FRAME_SIMPLE_SERVICE_H
#define MESSAGE_FRAME_SIMPLE_SERVICE_H

#include "service_base.h"
#include "service_handle.h"

class SimpleService : public ServiceBase {
public:
    SimpleService();

    virtual ~SimpleService() = default;

    int post(std::shared_ptr<ServiceHandle> handle);

};

#endif //MESSAGE_FRAME_SIMPLE_SERVICE_H
