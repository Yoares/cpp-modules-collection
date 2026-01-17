#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string& name) : name(name)
{
    for (int i = 0; i < 4; i++)
    {
        this->inventory[i] = NULL;
    }
}

Character::Character(const Character& other) : name(other.name)
{
    for (int i = 0; i < 4; i++)
    {
        this->inventory[i] = NULL;
    }
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
    }
}

Character& Character::operator=(const Character& other)
{
    // Protect against self-assignment
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete inventory[i];
            this->inventory[i] = NULL;
        }
        name = other.name;
        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this; 
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        delete inventory[i];
        inventory[i] = NULL;
    }
}

const std::string& Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;

    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
        return;

    if (inventory[idx])
        inventory[idx]->use(target);
}
