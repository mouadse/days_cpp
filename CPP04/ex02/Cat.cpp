#include "Cat.hpp"
#include "AAnimal.hpp"

Cat::Cat()
  : AAnimal()
{
    type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
  : AAnimal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
    this->type = other.type;
}

Cat&
Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        std::cout << "Cat assignment operator called" << std::endl;
        this->AAnimal::operator=(other);
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
        std::cout << "Cat assignment operator called (self-assignment)"
                  << std::endl;
    }
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    if (this->brain != NULL)
    {
        delete this->brain;
        this->brain = NULL;
    }
}

void
Cat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}

Brain*
Cat::getBrain() const
{
    return this->brain;
}
