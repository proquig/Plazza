//
// Created by pogam-_g on 4/11/16.
//

#include <string>
#include "PhoneNumber.h"

void Plazza::PhoneNumber::execute() {

}

void Plazza::PhoneNumber::setOrigin(const std::string &file) {
    this->file = std::ifstream(file);
}
