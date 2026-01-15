#include "Animal.hpp"

Animal::Animal() : type("")
{

}

Animal::Animal (const Animal &other){
    *this = other;
}

Animal& Animal::operator=(const Animal &other){
    if (this != &other){
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal()
{

}

std::string Animal::getType() const{
    return(this->type);
}

void Animal::makeSound() const {
    std::cout << "Animal makes a sound" << std::endl;
}
