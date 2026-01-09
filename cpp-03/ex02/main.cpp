#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap a("Fraggy");

    a.attack("Enemy");
    a.takeDamage(40);
    a.beRepaired(20);
    a.highFivesGuys();

    return 0;
}

