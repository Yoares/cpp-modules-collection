#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class AMateria
{
    protected:
        std::string type;
        // Stores the Materia type ("ice", "cure", etc.)

    public:
        AMateria();
        AMateria(const std::string& type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        virtual ~AMateria();
        const std::string& getType() const;
        virtual AMateria* clone() const = 0;
        // virtual void use(ICharacter& target);
        // Virtual (NOT pure)
        // Default behavior may exist
        // Can be overridden by derived classes
};

#endif // AMATERIA_HPP