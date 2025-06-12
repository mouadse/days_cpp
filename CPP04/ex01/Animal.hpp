#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal {
protected:
  std::string type;

public:
  Animal();
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);
  virtual ~Animal();

  std::string getType(void) const;
  virtual void makeSound(void) const;
};

#endif
