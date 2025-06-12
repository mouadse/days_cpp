#include "AAnimal.hpp"

AAnimal::AAnimal()
  : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
  : type(other.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal&
AAnimal::operator=(const AAnimal& other)
{
    if (this != &other)
    {
        std::cout << "Animal assignment operator called" << std::endl;
        this->type = other.type;
    }
    else
    {
        std::cout << "Self-assignment detected" << std::endl;
    }
    return (*this);
}

AAnimal::~AAnimal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string
AAnimal::getType(void) const
{
    return (this->type);
}
