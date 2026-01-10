#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name){
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){

    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target){
        if (this->hitPoints <= 0)
    {
        std::cout << "ScavTrap " << this->name
          << " cannot attack because it has no hit points left!"
          << std::endl;
        return;
    }
    if (this->energyPoints <= 0)
    {
        std::cout << "ScavTrap " << this->name
          << " cannot attack because it has no energy points left!"
          << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ScavTrap " << this->name
          << " attacks " << target
          << ", causing " << this->attackDamage
          << " points of damage!"
          << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode." << std::endl;
}
