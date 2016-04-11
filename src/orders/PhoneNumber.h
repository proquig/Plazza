//
// Created by pogam-_g on 4/11/16.
//

#ifndef CPP_PLAZZA_PHONENUMBER_H
#define CPP_PLAZZA_PHONENUMBER_H


#include "../IOrder.h"

namespace Plazza {
    class PhoneNumber : public IOrder {
    public:
        virtual void execute();
    };
}


#endif //CPP_PLAZZA_PHONENUMBER_H
