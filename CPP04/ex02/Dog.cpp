#include "Dog.hpp"
#include "AAnimal.hpp"

Dog::Dog()
  : AAnimal()
{
    type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
  : AAnimal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
    this->type = other.type;
}

Dog&
Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        std::cout << "Dog assignment operator called" << std::endl;
        AAnimal::operator=(other);
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
