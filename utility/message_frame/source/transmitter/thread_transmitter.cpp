//
// Created by liweigao on 17-10-30.
//

#include "thread_transmitter.h"
#include "partner_manager_base.h"
#include "handle.h"

ThreadTransmitter::ThreadTransmitter() : Transmitter() {

}

int ThreadTransmitter::post(std::shared_ptr<Handle> handle) {
    std::shared_ptr<PartnerManager> pmb = PartnerManagerBase::get_instance();
    std::shared_ptr<Identifier> identifier = handle->get_receiver_id();
    std::shared_ptr<Receiver> receiver = pmb->find_receiver(identifier);
    receiver->receive(handle);
    return 0;
}
