#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat()
  : Animal()
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
    return;
}

Cat::Cat(const Cat& other)
  : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    return;
}

Cat&
Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        std::cout << "Cat assignment operator called" << std::endl;
        this->Animal::operator=(other);
        this->type = other.type;
    }
    else
    {
        std::cout << "Cat assignment operator called (self-assignment)"
                  << std::endl;
    }
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}

void
Cat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}
