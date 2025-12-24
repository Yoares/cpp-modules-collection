#include "Zombie.hpp"

Zombie::Zombie() : name("Unamed") {}

Zombie::~Zombie(){std::cout << name << " is destroyed " << std::endl; }

Zombie::Zombie(std::string n) : name(n){}


void Zombie::announce() const{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n"; 
}

void Zombie::set_name(const std::string& name){
        this->name = name;
}