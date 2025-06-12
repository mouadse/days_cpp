#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
  : type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
  : type(other.type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal&
WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        std::cout << "WrongAnimal assignment operator called" << std::endl;
        this->type = other.type;
    }
    else
    {
        std::cout << "WrongAnimal assignment operator called (self-assignment)"
                  << std::endl;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string
WrongAnimal::getType(void) const
{
    return (this->type);
}

void
WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal sound" << std::endl;
}
