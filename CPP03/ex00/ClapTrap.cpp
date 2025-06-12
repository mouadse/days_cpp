#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
  : _name("Default")
  , _hitPoints(10)
  , _energyPoints(10)
  , _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
  : _name(name)
  , _hitPoints(10)
  , _energyPoints(10)
  , _attackDamage(0)
{
    std::cout << "ClapTrap Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
}

ClapTrap&
ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this == &other)
    {
        return (*this);
    }
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
}

void
ClapTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!"
                  << std::endl;
        _energyPoints--;
    }
    else if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name
                  << " cannot attack because it's out of hit points!"
                  << std::endl;
    }
    else if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name
                  << " is out of energy and cannot attack!" << std::endl;
    }
}

void
ClapTrap::takeDamage(unsigned int amount)
{
    if (!_hitPoints)
    {
        std::cout << "ClapTrap " << _name << " is dead and cannot take damage!"
                  << std::endl;
        return;
    }
    if (amount >= _hitPoints)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name
                  << " has taken fatal damage and is now dead!" << std::endl;
    }
    else
    {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount
                  << " points of damage! Remaining hit points: " << _hitPoints
                  << std::endl;
    }
}
void
ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " repairs itself and gains "
                  << amount << " hit points!" << std::endl;
    }
    else if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name
                  << " cannot be repaired because it's out of hit points!"
                  << std::endl;
    }
    else if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name
                  << " is out of energy and cannot be repaired!" << std::endl;
    }
}
