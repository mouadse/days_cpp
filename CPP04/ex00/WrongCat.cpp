#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
    //   this->WrongAnimal::type = "WrongCat"; to be inspected later
}

WrongCat::WrongCat(const WrongCat& other)
  : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat&
WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
    {
        std::cout << "WrongCat assignment operator called" << std::endl;
        this->WrongAnimal::operator=(other);
        this->type = other.type;
    }
    else
    {
        std::cout << "WrongCat assignment operator called (self-assignment)"
                  << std::endl;
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void
WrongCat::makeSound(void) const
{
    std::cout << "WrongCat sound" << std::endl;
}
