#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap a("Shiny");

    a.attack("Enemy");
    a.takeDamage(30);
    a.beRepaired(20);
    a.whoAmI();

    return 0;
}


