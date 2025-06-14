#ifndef CAT_HPP
#define CAT_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

#include <iostream>
#include <string>

class Cat : public AAnimal
{
  private:
    Brain* brain;

  public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();

    void   makeSound(void) const;
    Brain* getBrain() const;
};

#endif
