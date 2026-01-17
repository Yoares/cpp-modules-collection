#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    virtual ~Ice();
    virtual AMateria* clone() const;
    // virtual void use(ICharacter& target);e
    // Overrides AMateria::use
    // Applies Ice effect to target
};
#endif // ICE_HPP