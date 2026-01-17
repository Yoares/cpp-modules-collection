#include "AMateria.hpp"

AMateria::AMateria(){
    this->type = "default";
}

AMateria::AMateria(const std::string& type){
    this->type = type;
}

AMateria::AMateria(const AMateria& other){
    this->type = other.type; 
}

AMateria& AMateria::operator=(const AMateria& other){
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

AMateria::~AMateria(){
}

const std::string& AMateria::getType() const{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
