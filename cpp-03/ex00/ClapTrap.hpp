#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        int hit_point;
        int energy_point;
        int Attack_damage;
    public:
        ClapTrap();
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator =(const ClapTrap &other);
        ~ClapTrap();
        // the public function
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif