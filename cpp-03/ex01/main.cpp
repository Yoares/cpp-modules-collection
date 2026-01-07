#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap a("Ares");
    ScavTrap b("bob");
    // Normal actions
    a.attack("Target");
    a.takeDamage(3);
    a.beRepaired(2);

    //lll
    b.attack("leooooo");
    std::cout << std::endl;

    // Use all energy
    for (int i = 0; i < 10; i++)
        a.attack("Dummy");

    std::cout << std::endl;

    // Try actions with no energy
    a.attack("Ghost");
    a.beRepaired(5);

    std::cout << std::endl;

    // Kill ClapTrap
    a.takeDamage(50);

    // Try actions while dead
    a.attack("Zombie");
    a.beRepaired(10);

    return 0;
}
