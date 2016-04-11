//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_PHONENUMBER_H
#define CPP_PLAZZA_PHONENUMBER_H

#include <fstream>
#include "../IOrder.h"

namespace Plazza {
    class PhoneNumber : public IOrder {
        std::ifstream file;

    public:
        virtual void setOrigin(const std::string &file) override;

        virtual void execute() override ;
    };
}


#endif //CPP_PLAZZA_PHONENUMBER_H
