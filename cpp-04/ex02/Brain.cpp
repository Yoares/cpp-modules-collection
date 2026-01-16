#include "Brain.hpp"

Brain::Brain()
{
    // initialize ideas if needed
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    // copy all ideas from other
    for (int i = 0; i < 100; ++i)
    {
            this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other)
{
    // protect against self-assignment
    // copy all ideas
    // return *this
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
        {
            this->ideas[i] = other.ideas[i];
        }   
    }
    return *this;
}

Brain::~Brain()
{
    // nothing dynamic to delete
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}
