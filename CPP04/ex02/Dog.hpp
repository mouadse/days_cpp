#ifndef DOG_HPP
#define DOG_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

#include <iostream>
#include <string>

class Dog : public AAnimal
{
  private:
    Brain* brain;

  public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

    void   makeSound(void) const;
    Brain* getBrain() const;
};

#endif
