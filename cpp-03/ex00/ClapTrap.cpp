#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(10)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " constructed" << std::endl;
}


ClapTrap &ClapTrap::operator =(const ClapTrap &other)
{
    if (this != &other)
    {
        this->attackDamage = other.attackDamage;
        this->energyPoints = other.energyPoints;
        this->hitPoints = other.hitPoints;
        this->name = other.name;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name
          << " cannot attack because it has no hit points left!"
          << std::endl;
        return;
    }
    if (this->energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name
          << " cannot attack because it has no energy points left!"
          << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ClapTrap " << this->name
          << " attacks " << target
          << ", causing " << this->attackDamage
          << " points of damage!"
          << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount){
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name
            << " is already dead!" << std::endl;
        return;
    }
    if (amount >= (unsigned int)this->hitPoints)
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;

    std::cout << "ClapTrap " << this->name
              << " takes " << amount
              << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name
            << " is already dead!" << std::endl;
        return;
    }
    if (this->energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name
          << " cannot attack because it has no energy points left!"
          << std::endl;
        return;
    }

    this->energyPoints -= 1;
    this->hitPoints += amount;

    std::cout << "ClapTrap " << this->name
              << " repairs itself for " << amount
              << " hit points!"
              << std::endl;
}
