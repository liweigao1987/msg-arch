//
// Created by liweigao on 17-10-30.
//

#include "partner_manager_base.h"
#include "tools.h"

std::shared_ptr<PartnerManagerBase> PartnerManagerBase::s_partner_manager;
std::mutex PartnerManagerBase::s_mutex;

std::shared_ptr<PartnerManagerBase> PartnerManagerBase::get_instance() {
    if (s_partner_manager.get() == nullptr) {
        std::lock_guard<std::mutex> lg(s_mutex);
        if (s_partner_manager.get() == nullptr) {
            PartnerManagerBase *pmb = new PartnerManagerBase();
            s_partner_manager = std::shared_ptr<PartnerManagerBase>(pmb);
        }
    }
    return s_partner_manager;
}

PartnerManagerBase::PartnerManagerBase() {
    this->_partners = std::make_shared<std::map<std::shared_ptr<Identifier>, std::shared_ptr<Partner> > >();
}

int PartnerManagerBase::register_partner(std::shared_ptr<Partner> partner) {
    std::shared_ptr<Identifier> id = partner->get_identifier();
    if (!id) {
        id = std::make_shared<Identifier>();
        std::string uuid = Tools::get_uuid();
        id->set_uuid(uuid);
        partner->set_identifier(id);
    }
    this->_partners->emplace(id, partner);
    return 0;
}

int PartnerManagerBase::unregister_partner(std::shared_ptr<Partner> partner) {
    std::shared_ptr<Identifier> id = partner->get_identifier();
    this->_partners->erase(id);
    return 0;
}

std::shared_ptr<Partner> PartnerManagerBase::find(std::shared_ptr<Identifier> identifier) {
    std::map<std::shared_ptr<Identifier>, std::shared_ptr<Partner> >::iterator it;
    it = _partners->find(identifier);
    if (it != _partners->end()) {
        return it->second;
    } else {
        return nullptr;
    }
}