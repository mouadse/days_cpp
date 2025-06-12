#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
  : ClapTrap("Default ScavTrap")
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "Default ScavTrap constructed!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
  : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
  : ClapTrap(other)
{

    std::cout << "ScavTrap " << _name << " copied!" << std::endl;
}

ScavTrap&
ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap " << _name << " assigned!" << std::endl;
    }
    else
    {
        std::cout << "Self-assignment detected for ScavTrap " << _name << "!"
                  << std::endl;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destructed!" << std::endl;
}

void
ScavTrap::attack(const std::string& target)
{
    if (!this->_hitPoints || !this->_energyPoints)
    {
        std::cout
          << "ScavTrap " << this->_name
          << " cannot attack because it has no hit points or energy points!"
          << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target
                  << " causing " << this->_attackDamage << " points of damage!"
                  << std::endl;
        this->_energyPoints--;
    }
}

void
ScavTrap::guardGate() const
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode!"
              << std::endl;
}
