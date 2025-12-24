#include "Weapon.hpp"

Weapon::Weapon() : type("") {}

Weapon::Weapon(const std::string& type) : type(type) {}

const std::string& Weapon::getType() const {
    return this->type;
}

void Weapon::setType(const std::string& new_type){
    this->type = new_type;
}