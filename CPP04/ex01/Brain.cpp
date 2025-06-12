#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        if (i % 2 == 0)
        {
            this->ideas[i] = "Idea";
        }
        else
        {
            this->ideas[i] = "Thought";
        }
    }
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = other.ideas[i];
    }
}

Brain&
Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        std::cout << "Brain assignment operator called" << std::endl;
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    else
    {
        std::cout << "Brain assignment operator called on the same object"
                  << std::endl;
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

std::string
Brain::getIdea(int index) const
{
    if (index < 0 || index >= 100)
    {
        return "Invalid idea index";
    }
    return this->ideas[index];
}

void
Brain::setIdea(const std::string& idea, int index)
{
    if (index < 0 || index >= 100)
    {
        std::cerr << "Invalid idea index" << std::endl;
        return;
    }
    this->ideas[index] = idea;
}

void
Brain::printIdeas() const
{
    for (int i = 0; i < 100; i++)
    {
        std::cout << "Idea " << i << ": " << this->ideas[i] << std::endl;
    }
}
