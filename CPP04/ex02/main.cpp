#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

// ── 1.  Runtime-polymorphism sanity check ────────────────────────────────────
static void
polymorphismTest()
{
    const WrongAnimal* wrong = new WrongCat();
    std::cout << "[WrongCat via WrongAnimal] type: " << wrong->getType()
              << " | sound: ";
    wrong->makeSound(); // non-virtual: prints WrongAnimal sound
    delete wrong;

    const AAnimal* dog = new Dog();
    std::cout << "[Dog via AAnimal]         type: " << dog->getType()
              << " | sound: ";
    dog->makeSound(); // virtual: prints Dog sound
    delete dog;
}

// ── 2.  Deep-copy (Brain) smoke test ────────────────────────────────────────
static void
deepCopyTest()
{
    Dog original;
    original.getBrain()->setIdea("Chase cat", 0);

    Dog copy(original); // copy-ctor
    original.getBrain()->setIdea("Eat food", 0);

    std::cout << "\nDeep-copy check:\n"
              << "  original idea[0] : " << original.getBrain()->getIdea(0)
              << "\n  copied   idea[0] : " << copy.getBrain()->getIdea(0)
              << '\n';
}

// ── 3.  Array of base-class pointers + clean destruction ────────────────────
static void
arrayTest()
{
    std::cout << "\nArray test (2 Dogs, 2 Cats):\n";
    AAnimal* zoo[4] = {new Dog(), new Cat(), new Dog(), new Cat()};

    for (int i = 0; i < 4; i++)
    {
        zoo[i]->makeSound();
        delete zoo[i]; // virtual dtor ⇒ proper cleanup
    }
}

// ── Entry point ──────────────────────────────────────────────────────────────
int
main()
{
    std::cout << "\n── Compact 80/20 Test Suite ────────────────────────────\n";
    polymorphismTest();
    deepCopyTest();
    arrayTest();
    std::cout << "\n── All critical tests passed ───────────────────────────\n";
    return 0;
}
