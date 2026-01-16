#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog (const Dog &other) : Animal(other) {
    this->brain = new Brain(*(other.brain));
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other){
    if (this != &other)
    {
        Animal::operator=(other);
        delete(this->brain);
        this->brain = new Brain(*(other.brain));
    }
    return *this;
}

Dog::~Dog(){
    delete this->brain;
    this->brain = NULL;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}
/*
Dog::Dog()
{
    // set type = "Dog"
    // allocate Brain on heap
    // brain must be valid after construction
}

Dog::Dog(const Dog& other) : Animal(other)
{
    // allocate a NEW Brain
    // deep copy other's Brain into this Brain
}

Dog& Dog::operator=(const Dog& other)
{
    // protect against self-assignment

    // copy Animal part (type)

    // delete existing Brain
    // allocate new Brain
    // deep copy other's Brain

    // return *this
}

Dog::~Dog()
{
    // delete Brain
    // set brain pointer to null (defensive)
}

void Dog::makeSound() const
{
    // print dog sound
}
*/