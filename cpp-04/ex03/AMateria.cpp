#include "AMateria.hpp"

AMateria::AMateria(){
    this->type = "default";
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type){
    this->type = type;
    std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other){
    this->type = other.type; 
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other){
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "AMateria assignment operator called" << std::endl;
    return *this;
}

AMateria::~AMateria(){
    std::cout << "AMateria destructor called" << std::endl;
}

const std::string& AMateria::getType() const{
    return this->type;
}
