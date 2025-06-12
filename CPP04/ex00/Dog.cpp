#include "Dog.hpp"

Dog::Dog()
  : Animal()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
    return;
}

Dog::Dog(const Dog& other)
  : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    return;
}

Dog&
Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        std::cout << "Dog assignment operator called" << std::endl;
        this->Animal::operator=(other);
        this->type = other.type;
    }
    else
    {
        std::cout << "Dog assignment operator called (self-assignment)"
                  << std::endl;
    }
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

void
Dog::makeSound(void) const
{
    std::cout << "Woof!" << std::endl;
}
