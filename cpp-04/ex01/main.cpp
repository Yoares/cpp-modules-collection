#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "----------------------------------------" << std::endl;
    delete j;//should not create a leak
    delete i;
    std::cout << "------------------------------test_2--------------------------------" << std::endl;
    Dog* dog = new Dog();
    std::cout << "----------------------------------------" << std::endl;
    Dog* copy = new Dog(*dog);
    std::cout << "----------------------------------------" << std::endl;
    delete dog; // Check if this deletes 'copy's brain (it shouldn't)
    delete copy;

    return 0;
}

