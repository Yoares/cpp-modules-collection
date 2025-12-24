#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie();                         // Default constructor
    Zombie(std::string n);            // Param constructor
    ~Zombie();                        // Destructor

    void announce() const;            // FIXED spelling
    void set_name(const std::string& name);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif

