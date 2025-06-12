#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog()
  : Animal()
{
    type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
  : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
    this->type = other.type; // May remove it later
}

Dog&
Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        std::cout << "Dog assignment operator called" << std::endl;
        Animal::operator=(other);
        if (this->brain != NULL)
        {
            delete this->brain;
            this->brain = NULL;
        }
        this->brain = new Brain(*other.brain);
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
    if (this->brain != NULL)
    {
        delete this->brain;
        this->brain = NULL;
    }
}

void
Dog::makeSound(void) const
{
    std::cout << "Woof!" << std::endl;
}

Brain*
Dog::getBrain() const
{
    return this->brain;
}
