#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int
main()
{
    // Test basic polymorphism
    std::cout << "=== Basic Polymorphism ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    meta->makeSound();
    dog->makeSound();
    cat->makeSound();

    delete meta;
    delete dog;
    delete cat;
    std::cout << std::endl;

    // Test wrong implementation (non-virtual)
    std::cout << "=== Wrong Implementation ===" << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();
    wrongCat->makeSound(); // Should call WrongAnimal's method
    delete wrongCat;
    std::cout << std::endl;

    // Test array polymorphism
    std::cout << "=== Array Test ===" << std::endl;
    const Animal* animals[4] = {new Dog(), new Cat(), new Dog(), new Cat()};

    for (int i = 0; i < 4; ++i)
    {
        animals[i]->makeSound();
        delete animals[i];
    }

    return 0;
}
