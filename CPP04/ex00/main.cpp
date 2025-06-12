#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int
main()
{
    // Testing Animal class
    std::cout << "--- Testing Animal ---" << std::endl;
    const Animal* meta = new Animal();
    std::cout << "Type: " << meta->getType() << std::endl;
    meta->makeSound(); // Should output generic animal sound
                       //   delete meta; Delete deleted
    std::cout << std::endl;

    // Testing Dog class
    std::cout << "--- Testing Dog ---" << std::endl;
    const Animal* j = new Dog();
    std::cout << "Type: " << j->getType() << std::endl;
    j->makeSound(); // Should output dog sound
    delete j;
    std::cout << std::endl;

    // Testing Cat class
    std::cout << "--- Testing Cat ---" << std::endl;
    const Animal* i = new Cat();
    std::cout << "Type: " << i->getType() << std::endl;
    i->makeSound(); // Should output cat sound
    delete i;
    std::cout << std::endl;

    // Testing copy constructor and assignment operator for Dog
    std::cout << "--- Testing Dog Copy/Assignment ---" << std::endl;
    Dog dog1;
    Dog dog2(dog1); // Copy constructor
    Dog dog3;
    dog3 = dog1; // Assignment operator
    dog1.makeSound();
    dog2.makeSound();
    dog3.makeSound();
    std::cout << std::endl;

    // Testing copy constructor and assignment operator for Cat
    std::cout << "--- Testing Cat Copy/Assignment ---" << std::endl;
    Cat cat1;
    Cat cat2(cat1); // Copy constructor
    Cat cat3;
    cat3 = cat1; // Assignment operator
    cat1.makeSound();
    cat2.makeSound();
    cat3.makeSound();
    std::cout << std::endl;

    // Testing WrongAnimal class (non-virtual makeSound)
    std::cout << "--- Testing WrongAnimal ---" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    std::cout << "Type: " << wrongMeta->getType() << std::endl;
    wrongMeta->makeSound(); // Should output generic wrong animal sound
    delete wrongMeta;
    std::cout << std::endl;

    // Testing WrongCat class (non-virtual makeSound in base)
    std::cout << "--- Testing WrongCat ---" << std::endl;
    const WrongAnimal* wrongI = new WrongCat();
    std::cout << "Type: " << wrongI->getType() << std::endl;
    wrongI->makeSound(); // Should output WrongAnimal sound due to non-virtual
                         // makeSound in WrongAnimal
    delete wrongI;
    std::cout << std::endl;

    // Testing WrongCat directly
    std::cout << "--- Testing WrongCat Directly ---" << std::endl;
    const WrongCat* directWrongCat = new WrongCat();
    std::cout << "Type: " << directWrongCat->getType() << std::endl;
    directWrongCat->makeSound(); // Should output WrongCat sound
    delete directWrongCat;
    std::cout << std::endl;

    // Test array of Animals
    std::cout << "--- Testing Array of Animals ---" << std::endl;
    const Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int k = 0; k < 4; ++k)
    {
        std::cout << "Animal " << k << " Type: " << animals[k]->getType()
                  << std::endl;
        animals[k]->makeSound();
        delete animals[k];
    }
    std::cout << std::endl;

    // Test polymorphism with references
    std::cout << "--- Testing Polymorphism with References ---" << std::endl;
    Dog     concreteDog;
    Cat     concreteCat;
    Animal& animalRefDog = concreteDog;
    Animal& animalRefCat = concreteCat;

    std::cout << "Dog (via ref) Type: " << animalRefDog.getType() << std::endl;
    animalRefDog.makeSound();
    std::cout << "Cat (via ref) Type: " << animalRefCat.getType() << std::endl;
    animalRefCat.makeSound();
    std::cout << std::endl;

    return 0;
}
