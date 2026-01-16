#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat Constructer is called" << std::endl;
}

Cat::Cat (const Cat &other) : Animal(other){
    this->brain = new Brain(*(other.brain));
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other){
    if (this != &other)
    {
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*(other.brain));
    }
    return *this;
}

Cat::~Cat()
{
    delete this->brain;
    this->brain = NULL;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
