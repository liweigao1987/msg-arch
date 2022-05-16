//
// Created by liweigao on 17-10-30.
//

#ifndef MESSAGE_FRAME_PARTNER_MANAGER_BASE_H
#define MESSAGE_FRAME_PARTNER_MANAGER_BASE_H

#include <map>
#include <mutex>
#include <memory>

#include "partner_manager.h"

class PartnerManagerBase : public PartnerManager {
public:
    static std::shared_ptr<PartnerManagerBase> get_instance();

    virtual ~PartnerManagerBase() = default;

    virtual int register_partner(std::shared_ptr<Partner> partner);

    virtual int unregister_partner(std::shared_ptr<Partner> partner);

    virtual std::shared_ptr<Partner> find(std::shared_ptr<Identifier> identifier);

    virtual std::shared_ptr<PartnerBase> find_partner_base(std::shared_ptr<Identifier> identifier) {
        std::shared_ptr<Partner> partner = find(identifier);
        std::shared_ptr<PartnerBase> pb = std::dynamic_pointer_cast<PartnerBase>(partner);
        return pb;
    }

protected:
    std::shared_ptr<std::map<std::shared_ptr<Identifier>, std::shared_ptr<Partner> > > _partners;

private:
    static std::shared_ptr<PartnerManagerBase> s_partner_manager;
    static std::mutex s_mutex;

    PartnerManagerBase();
};

#endif //MESSAGE_FRAME_PARTNER_MANAGER_BASE_H
