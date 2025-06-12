#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "Default constructor called" << std::endl;
  return;
}

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "Parameterized constructor called" << std::endl;
  return;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  std::cout << "Copy constructor called" << std::endl;
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  return;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this == &other) {
    return (*this);
  }
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  return (*this);
}

ClapTrap::~ClapTrap() {
  std::cout << _name << " has been destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
  if (!_hitPoints || !_energyPoints) {
    std::cout << "ClapTrap " << _name
              << " has no energy or hit points to attack!" << std::endl;
    return;
  }
  _energyPoints--;
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (!_hitPoints) {
    std::cout << "ClapTrap " << _name << " is dead and cannot take damage!"
              << std::endl;
    return;
  }
  if (amount >= _hitPoints) {
    _hitPoints = 0;
    std::cout << "ClapTrap " << _name
              << " has taken fatal damage and is now dead!" << std::endl;
  } else {
    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount
              << " points of damage! Remaining hit points: " << _hitPoints
              << std::endl;
  }
}
void ClapTrap::beRepaired(unsigned int amount) {
  if (!_hitPoints || !_energyPoints) {
    std::cout << "ClapTrap " << _name
              << " has no energy or hit points to be repaired!" << std::endl;
    return;
  }
  _energyPoints--;
  _hitPoints += amount;
  std::cout << "ClapTrap " << _name << " has been repaired for " << amount
            << " points! Remaining hit points: " << _hitPoints
            << ", Remaining energy points: " << _energyPoints << std::endl;
}
