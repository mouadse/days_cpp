#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>


static void
soundTest()
{
    std::cout << "\n[Polymorphism check]\n";
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    dog->makeSound(); // Dog bark
    cat->makeSound(); // Cat meow

    const WrongAnimal* wrong = new WrongCat();
    wrong->makeSound(); // WrongAnimal sound (non-virtual)

    delete dog;
    delete cat;
    delete wrong;
}


static void
brainCopyTest()
{
    Dog original;
    original.getBrain()->setIdea("Chase cat", 0);

    Dog copy(original); // copy-ctor
    original.getBrain()->setIdea("Eat food", 0);

    std::cout << "\n[Brain deep-copy]\n"
              << "  original idea[0] : " << original.getBrain()->getIdea(0)
              << "\n  copied   idea[0] : " << copy.getBrain()->getIdea(0)
              << '\n';
}

static void
zooTest()
{
    std::cout << "\n[Destructor / array check]\n";
    Animal* zoo[4] = {new Dog(), new Cat(), new Dog(), new Cat()};
    for (int i = 0; i < 4; i++)
    {
        zoo[i]->makeSound();
        delete zoo[i]; // virtual dtor ⇒ correct cleanup / no leaks
    }
}

int
main()
{
    std::cout << "\n── Compact 80/20 Test Suite ────────────────────────────\n";
    soundTest();
    brainCopyTest();
    zooTest();
    std::cout << "\n── All critical tests passed ───────────────────────────\n";
    return 0;
}
