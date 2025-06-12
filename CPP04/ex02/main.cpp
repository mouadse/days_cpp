#include "AAnimal.hpp"
#include "Brain.hpp" // Assuming Brain header is needed for deep copy tests
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <exception> // For std::exception (though direct use might be limited without custom exceptions)
#include <iostream>
#include <string> // For std::string

void
testWrongAnimalBehavior()
{
    std::cout << "\n--- Test: WrongAnimal and WrongCat Behavior ---"
              << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat(); // Should be WrongCat
    const WrongCat*    wrongCatConcrete = new WrongCat();

    std::cout << "Type of wrongMeta: " << wrongMeta->getType() << std::endl;
    std::cout << "Type of wrongI (WrongCat): " << wrongI->getType()
              << std::endl;

    std::cout << "Sound of wrongMeta: ";
    wrongMeta->makeSound();
    std::cout << "Sound of wrongI (WrongCat pointer by WrongAnimal): ";
    wrongI->makeSound(); // Will likely call WrongAnimal's sound due to
                         // non-virtual makeSound
    std::cout << "Sound of wrongCatConcrete (WrongCat direct): ";
    wrongCatConcrete->makeSound(); // Will call WrongCat's sound

    delete wrongMeta;
    delete wrongI;
    delete wrongCatConcrete;
}

void
testDeepCopy()
{
    std::cout << "\n--- Test: Deep Copy for Dog and Cat (Brain) ---"
              << std::endl;
    Dog* originalDog = new Dog();
    originalDog->getBrain()->setIdea("Original Dog Idea 1", 0);
    originalDog->getBrain()->setIdea("Original Dog Idea 2", 1);

    Cat* originalCat = new Cat();
    originalCat->getBrain()->setIdea("Original Cat Idea 1", 0);

    std::cout << "\n--- Dog Deep Copy Test ---" << std::endl;
    Dog* copiedDog = new Dog(*originalDog); // Copy constructor
    // Modify original dog's brain AFTER copy
    originalDog->getBrain()->setIdea("MODIFIED Original Dog Idea 1 after copy",
                                     0);

    std::cout << "Original Dog First Idea: "
              << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog First Idea (should be original): "
              << copiedDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Original Dog Second Idea: "
              << originalDog->getBrain()->getIdea(1) << std::endl;
    std::cout << "Copied Dog Second Idea: " << copiedDog->getBrain()->getIdea(1)
              << std::endl;

    Dog assignedDog;
    assignedDog = *originalDog; // Assignment operator
    // Modify original dog's brain AFTER assignment
    originalDog->getBrain()->setIdea(
      "RE-MODIFIED Original Dog Idea 1 after assignment", 0);
    std::cout << "Original Dog First Idea (after assign mod): "
              << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout
      << "Assigned Dog First Idea (should be from before re-modification): "
      << assignedDog.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- Cat Deep Copy Test ---" << std::endl;
    Cat* copiedCat = new Cat(*originalCat); // Copy constructor
    originalCat->getBrain()->setIdea("MODIFIED Original Cat Idea 1 after copy",
                                     0);

    std::cout << "Original Cat First Idea: "
              << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Cat First Idea (should be original): "
              << copiedCat->getBrain()->getIdea(0) << std::endl;

    Cat assignedCat;
    assignedCat = *originalCat; // Assignment operator
    originalCat->getBrain()->setIdea(
      "RE-MODIFIED Original Cat Idea 1 after assignment", 0);
    std::cout << "Original Cat First Idea (after assign mod): "
              << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout
      << "Assigned Cat First Idea (should be from before re-modification): "
      << assignedCat.getBrain()->getIdea(0) << std::endl;

    delete originalDog;
    delete copiedDog;
    delete originalCat;
    delete copiedCat;
}

void
testArrayOfAnimals()
{
    std::cout << "\n--- Test: Array of Animals ---" << std::endl;
    const int arraySize = 10;
    AAnimal*  animals[arraySize];

    std::cout << "Creating " << arraySize
              << " animals (half Dogs, half Cats)..." << std::endl;
    for (int k = 0; k < arraySize; ++k)
    {
        if (k < arraySize / 2)
        {
            animals[k] = new Dog();
        }
        else
        {
            animals[k] = new Cat();
        }
    }

    std::cout << "\nMaking sounds from the array..." << std::endl;
    for (int k = 0; k < arraySize; ++k)
    {
        std::cout << "Animal #" << k << " (" << animals[k]->getType() << "): ";
        animals[k]->makeSound();
    }

    // Test ideas in brains of array elements (example for first dog and first
    // cat)
    if (arraySize > 0)
    {
        Dog* firstDogInArray = dynamic_cast<Dog*>(animals[0]);
        if (firstDogInArray)
        {
            firstDogInArray->getBrain()->setIdea("Dog in array idea", 0);
            std::cout << "First dog in array, idea 0: "
                      << firstDogInArray->getBrain()->getIdea(0) << std::endl;
        }
    }
    if (arraySize > arraySize / 2)
    {
        Cat* firstCatInArray = dynamic_cast<Cat*>(animals[arraySize / 2]);
        if (firstCatInArray)
        {
            firstCatInArray->getBrain()->setIdea("Cat in array idea", 0);
            std::cout << "First cat in array, idea 0: "
                      << firstCatInArray->getBrain()->getIdea(0) << std::endl;
        }
    }

    std::cout << "\nDeleting all animals in the array..." << std::endl;
    for (int k = 0; k < arraySize; ++k)
    {
        delete animals[k];
        animals[k] = NULL; // Good practice
    }
    std::cout << "All animals in array deleted." << std::endl;
}

void
testScopeAndDestruction()
{
    std::cout << "\n--- Test: Scope and Destruction ---" << std::endl;
    std::cout << "Creating Dog on the stack..." << std::endl;
    {
        Dog stackDog;
        stackDog.getBrain()->setIdea("Stack dog idea", 0);
        std::cout << "Stack Dog Type: " << stackDog.getType() << ", Sound: ";
        stackDog.makeSound();
        std::cout << "Stack Dog Idea: " << stackDog.getBrain()->getIdea(0)
                  << std::endl;
        std::cout << "Stack Dog going out of scope..." << std::endl;
    } // stackDog destructor called here
    std::cout << "Stack Dog out of scope." << std::endl;

    std::cout << "\nCreating Cat on the stack..." << std::endl;
    {
        Cat stackCat;
        stackCat.getBrain()->setIdea("Stack cat idea", 0);
        std::cout << "Stack Cat Type: " << stackCat.getType() << ", Sound: ";
        stackCat.makeSound();
        std::cout << "Stack Cat Idea: " << stackCat.getBrain()->getIdea(0)
                  << std::endl;
        std::cout << "Stack Cat going out of scope..." << std::endl;
    } // stackCat destructor called here
    std::cout << "Stack Cat out of scope." << std::endl;
}

void
testBrainIndividually()
{
    std::cout << "\n--- Test: Brain Class Individually ---" << std::endl;
    Brain b1;
    b1.setIdea("First thought", 0);
    b1.setIdea("Last thought", 99);
    std::cout << "b1 idea 0: " << b1.getIdea(0) << std::endl;
    std::cout << "b1 idea 99: " << b1.getIdea(99) << std::endl;

    // Test out of bounds access (assuming getIdea handles it gracefully, e.g.,
    // returns empty string or specific message)
    std::cout << "b1 idea 100 (out of bounds): " << b1.getIdea(100)
              << std::endl;
    // Test setting out of bounds (assuming setIdea handles it gracefully)
    b1.setIdea("This should not be set", 100);
    std::cout
      << "b1 idea 100 after trying to set (should still be default/empty): "
      << b1.getIdea(100) << std::endl;

    Brain b2;
    b2.setIdea("b2 initial idea", 0);
    std::cout << "b2 idea 0 (before copy): " << b2.getIdea(0) << std::endl;

    Brain b3 = b1; // Copy constructor
    b1.setIdea("Modified b1 after b3 copy", 0);
    std::cout << "b1 idea 0 (after b3 copy & mod): " << b1.getIdea(0)
              << std::endl;
    std::cout << "b3 idea 0 (should be original b1 idea): " << b3.getIdea(0)
              << std::endl;
    std::cout << "b3 idea 99 (should be original b1 idea): " << b3.getIdea(99)
              << std::endl;

    b2 = b1; // Assignment operator
    b1.setIdea("Modified b1 after b2 assignment", 0);
    std::cout << "b1 idea 0 (after b2 assignment & mod): " << b1.getIdea(0)
              << std::endl;
    std::cout << "b2 idea 0 (should be b1's idea at time of assignment): "
              << b2.getIdea(0) << std::endl;
    std::cout << "b2 idea 99 (should be b1's idea at time of assignment): "
              << b2.getIdea(99) << std::endl;
    std::cout << "Brain tests finished." << std::endl;
}

int
main()
{
    std::cout << "--- Starting Full Test Suite ---" << std::endl;

    testWrongAnimalBehavior();
    testDeepCopy(); // This will heavily rely on Brain's copy constructor and
                    // assignment operator
    testArrayOfAnimals();
    testScopeAndDestruction();
    testBrainIndividually(); // Test Brain copy semantics more directly

    std::cout << "\n--- All Tests Completed ---" << std::endl;

    // Example of how you might "trigger an issue" or test a specific failure
    // case This is more about demonstrating behavior than C++ try/catch for std
    // exceptions unless your classes are designed to throw them.
    std::cout << "\n--- Demonstrating Potential Issues (Conceptual) ---"
              << std::endl;
    std::cout << "If WrongAnimal's destructor wasn't virtual and you deleted a "
                 "WrongCat* via a WrongAnimal*,"
              << std::endl;
    std::cout
      << "(This test suite assumes destructors are correctly implemented as "
         "virtual where needed for base classes)."
      << std::endl;

    std::cout << "\nIf Brain did not implement deep copy, modifying an "
                 "original's idea would also modify the copy's idea."
              << std::endl;
    std::cout << "(The deep copy test above is designed to verify this is NOT "
                 "happening)."
              << std::endl;

    // To "trigger" an issue like an unhandled exception, you'd typically need
    // to:
    // 1. Dereference a NULL pointer (results in undefined behavior, often a
    // crash)
    //    Example: Animal* p = NULL; p->makeSound(); // CRASH
    // 2. Access an array out of bounds (undefined behavior)
    //    Example: int arr[5]; arr[10] = 1;
    // 3. new failing (throws std::bad_alloc)
    // try {
    //     // Try to allocate an enormous amount of memory
    //     char* p = new char[1000000000000000000ULL];
    //     delete[] p; // Should not reach here
    // } catch (const std::bad_alloc& e) {
    //     std::cerr << "Caught std::bad_alloc as expected: " << e.what() <<
    //     std::endl;
    // } catch (const std::exception& e) {
    //     std::cerr << "Caught some other std::exception: " << e.what() <<
    //     std::endl;
    // }

    std::cout << "\n--- End of Main ---" << std::endl;
    // system("leaks a.out"); // Useful on macOS with appropriate executable
    // name
    return 0;
}
