#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : name(name), hit_point(10), energy_point(10), Attack_damage(10)
{
}

ClapTrap::~ClapTrap()
{
    std::cout << "The destructor is called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
}

ClapTrap &ClapTrap::operator =(const ClapTrap &other)
{
    if (this != &other)
    {
        this->Attack_damage = other.Attack_damage;
        this->energy_point = other.energy_point;
        this->hit_point = other.hit_point;
        this->name = other.name;
    }
}

void ClapTrap::attack(const std::string& target)
{
    
}