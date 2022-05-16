//
// Created by liweigao on 17-10-26.
//

#ifndef MESSAGE_FRAME_MEDIATOR_BASE_H
#define MESSAGE_FRAME_MEDIATOR_BASE_H

#include <memory>

#include "mediator.h"
#include "thread_pool.h"
#include "partner_manager_base.h"

class MediatorBase : public Mediator {
public:
    MediatorBase();

    int post(std::shared_ptr<Handle> handle);

protected:
    std::shared_ptr<ThreadPool> _thread_pool;
    std::shared_ptr<PartnerManager> _partner_manager;

};

#endif //MESSAGE_FRAME_MEDIATOR_BASE_H
