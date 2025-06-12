#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
#include <string>

class WrongAnimal
{
  protected:
    std::string type;

  public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    virtual ~WrongAnimal();

    std::string getType(void) const;
    //   virtual void makeSound(void) const;
    void makeSound(void) const;
};

#endif
