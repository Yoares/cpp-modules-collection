#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}

void HumanB::setWeapon(Weapon& weapon){
    this->weapon = &weapon;
}

 void HumanB::attack() const{
    if (!weapon)
    {
        std::cout << this->name << " has no weapon to attack with" << std::endl;
        return;
    }
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
 }