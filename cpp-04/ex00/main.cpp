#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound(); // Cat sound
    j->makeSound(); // Dog sound
    meta->makeSound();

    const WrongAnimal* k = new WrongCat();
    k->makeSound(); // WrongAnimal sound (EXPECTED)

    delete meta;
    delete j;
    delete i;
    delete k;

    return 0;
}
