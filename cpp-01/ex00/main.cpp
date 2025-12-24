#include "Zombie.hpp"

int main() {
    Zombie* z = newZombie("Ares");
    z->announce();
    delete z;

    randomChump("malik");
}
