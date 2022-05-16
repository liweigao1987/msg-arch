//
// Created by liweigao on 17-11-6.
//

#include <iostream>

#include "simple_service.h"
#include "service_manager_base.h"
#include "mediator_base.h"

SimpleService::SimpleService() : ServiceBase() {
    this->_partner = std::make_shared<PartnerBase>();
    std::shared_ptr<Mediator> mediator = std::make_shared<MediatorBase>();
    this->_partner->set_mediator(mediator);
    std::shared_ptr<PartnerManagerBase> partner_manager = PartnerManagerBase::get_instance();
    partner_manager->register_partner(this->_partner);
    std::shared_ptr<ServiceManagerBase> smb = ServiceManagerBase::get_instance();
    std::shared_ptr<SimpleService> ss = std::shared_ptr<SimpleService>(this);
    smb->register_service(ss);
    this->_service_id->set_partner_id(this->_partner->get_identifier());
}

//todo : one to many
int SimpleService::post(std::shared_ptr<ServiceHandle> handle) {
    std::shared_ptr<Handle> message_handle = handle->get_message_handle();
    if (message_handle) {
        std::shared_ptr<std::set<std::shared_ptr<ServiceId> > > service_ids = handle->get_service_ids();
        for (std::shared_ptr<ServiceId> id : (*service_ids.get())) {
            std::shared_ptr<Identifier> receiver_id = id->get_partner_id();
            if (!receiver_id) {
                std::cout << "receiver_id is null" << std::endl;
                return -1;
            } else {
                message_handle->set_sender_id(this->_partner->get_identifier());
                message_handle->set_receiver_id(receiver_id);
                this->_partner->send(message_handle);
            }
        }
        return 0;
    } else {
        std::cout << "message_handle is null" << std::endl;
        return -1;
    }
}
