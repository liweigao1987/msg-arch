//
// Created by liweigao on 17-10-26.
//

#include "mediator_base.h"

MediatorBase::MediatorBase() {
    _thread_pool = std::make_shared<ThreadPool>(1);
}

int MediatorBase::post(std::shared_ptr<Handle> handle) {
    std::shared_ptr<PartnerManagerBase> pmb = PartnerManagerBase::get_instance();
    std::shared_ptr<Identifier> receiver_id = handle->get_receiver_id();
    std::shared_ptr<PartnerBase> receiver = pmb->find_partner_base(receiver_id);
    int ret = receiver->receive(handle);
    return ret;
}


