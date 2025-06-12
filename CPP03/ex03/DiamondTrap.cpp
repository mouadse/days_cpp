#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

