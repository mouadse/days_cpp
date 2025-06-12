#include "Animal.hpp"

Animal::Animal()
  : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
  : type(other.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal&
Animal::operator=(const Animal& other)
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

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string
Animal::getType(void) const
{
    return (this->type);
}

void
Animal::makeSound(void) const
{
    std::cout << "Animal sound" << std::endl;
}
