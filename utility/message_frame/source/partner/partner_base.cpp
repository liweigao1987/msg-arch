//
// Created by liweigao on 17-11-8.
//

#include <iostream>
#include <vector>

#include "partner_base.h"

int PartnerBase::send(std::shared_ptr<Handle> handle) {
    return this->_mediator->post(handle);
}

int PartnerBase::receive(std::shared_ptr<Handle> handle) {
    std::cout << "ReceiverBase = " << this << std::endl;
    std::cout << "handle = " << handle->to_string() << std::endl;
    std::shared_ptr<Content> content = handle->get_content();
    if (typeid(*(content.get())) ==
        typeid(ContentBase<std::shared_ptr<std::vector<int> > >)) {
        std::cout << "---vector" << std::endl;
        using Cbv = ContentBase<std::shared_ptr<std::vector<int> > >;
        std::shared_ptr<Cbv> cb = std::dynamic_pointer_cast<Cbv>(content);
        std::shared_ptr<std::vector<int> > vec = cb->get_any();
        int size = vec->size();
        for (int i=0; i<size; i++) {
            std::cout << "i=" << i << "-->" << vec->at(i) << std::endl;
        }
    } else if (typeid(*(content.get())) == typeid(ContentBase<std::string>)) {
        std::shared_ptr<ContentBase<std::string> > str = std::dynamic_pointer_cast<ContentBase<std::string> >(content);
        std::cout << "string=" << str->get_any() << std::endl;
    }
    return 0;
}
