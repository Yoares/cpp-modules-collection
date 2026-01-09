#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap a("Guardian");

    a.attack("Intruder");
    a.takeDamage(30);
    a.beRepaired(10);
    a.guardGate();

    return 0;
}

