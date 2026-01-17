#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class AMateria
{
protected:
    std::string type;
    // Stores the Materia type ("ice", "cure", etc.)
    // Protected so derived classes can set it

public:
    AMateria();
    // Default constructor
    // Initializes the base part of a Materia

    AMateria(const std::string& type);
    // Constructor that sets the Materia type
    // Used by derived classes

    AMateria(const AMateria& other);
    // Copy constructor
    // Copies only base-level data (type)

    AMateria& operator=(const AMateria& other);
    // Assignment operator
    // Copies only base-level data (type)

    virtual ~AMateria();
    // MUST be virtual
    // Allows safe deletion via AMateria*

    const std::string& getType() const;
    // Returns the Materia type
    // Does NOT expose ownership

    virtual AMateria* clone() const = 0;
    // PURE VIRTUAL
    // Forces derived classes to implement deep copy
    // Returns a NEW object allocated on the heap

    // virtual void use(ICharacter& target);
    // Virtual (NOT pure)
    // Default behavior may exist
    // Can be overridden by derived classes
};

#endif // AMATERIA_HPP