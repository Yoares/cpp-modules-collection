#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("Ares");

    a.attack("Enemy");
    a.takeDamage(5);
    a.beRepaired(3);

    a.takeDamage(20);      // kill
    a.attack("Ghost");    // should not work
    a.beRepaired(5);      // should not work

    return 0;
}

