#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::cout << "FragTrap " << _name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  if (this != &other) {
    std::cout << "FragTrap assignment operator called" << std::endl;
    ClapTrap::operator=(other);
  } else {
    std::cout << "Self-assignment detected, no action taken." << std::endl;
  }
  return *this;
}

// Destructor
FragTrap::~FragTrap(void) {
  std::cout << "FragTrap " << _name << " destructed!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}
