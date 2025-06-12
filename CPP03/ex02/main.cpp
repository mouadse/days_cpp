#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>
int
main()
{
    ClapTrap a("Alpha");
    ClapTrap b("Beta");
    ClapTrap c(a);
    b = ClapTrap("Temp");

    a.attack("Beta");
    b.takeDamage(3);
    b.beRepaired(2);

    for (int i = 0; i < 11; ++i)
    {
        a.attack("Target");
    }

    b.takeDamage(100);
    b.attack("X");
    b.beRepaired(5);

    ScavTrap s("Guardian");
    ScavTrap s2(s); // copy ctor

    s.attack("Enemy");
    s.takeDamage(40);
    s.beRepaired(20);
    s.guardGate();

    for (int i = 0; i < 11; ++i)
    {
        s2.attack("Dummy");
    }
    s2.guardGate();
    s2.takeDamage(200);
    s2.attack("Dummy");

    FragTrap f("Bomber");
    FragTrap f2(f);

    f.attack("Enemy");
    f.takeDamage(25);
    f.beRepaired(15);
    f.highFivesGuys();

    for (int i = 0; i < 11; ++i)
    {
        f.attack("Dummy");
    }
    f.highFivesGuys();
    f2.takeDamage(200);
    f2.attack("Dummy");
    f2.highFivesGuys();

    return 0;
}
// // Helper function to print test section headers
// void
// printTestHeader(const std::string& title)
// {
//     std::cout << "\n==============================================\n";
//     std::cout << "   " << title << "\n";
//     std::cout << "==============================================\n";
// }

// // Helper function for testing energy depletion
// void
// depleteEnergy(ClapTrap&          trap,
//               const std::string& target,
//               const std::string& trapType)
// {
//     unsigned int count = 0;
//     std::cout << "\nDepleting " << trapType << "'s energy..." << std::endl;

//     // Keep attacking until energy is depleted
//     for (int i = 0; i < 15; i++)
//     { // Max 15 attacks to avoid infinite loop
//         std::cout << "Attack #" << ++count << ": ";
//         trap.attack(target);
//     }

//     std::cout << "Energy depletion test complete.\n" << std::endl;
// }

// int
// main()
// {
//     // ================= CLAPTRAP TESTS =================
//     printTestHeader("CLAPTRAP BASIC TESTS");

//     // Test constructors
//     std::cout << "Testing ClapTrap constructors:" << std::endl;
//     ClapTrap c1("Alpha");
//     ClapTrap c2("Beta");
//     ClapTrap c3(c1);  // Test copy constructor
//     ClapTrap c4 = c2; // Test copy assignment

//     // Basic attack, damage and repair functionality
//     std::cout << "\nTesting basic attack, damage, repair functionality:"
//               << std::endl;
//     c1.attack("Beta");
//     c2.takeDamage(3);
//     c2.beRepaired(2);

//     // Testing edge cases
//     printTestHeader("CLAPTRAP EDGE CASES");

//     // Test 1: Energy depletion
//     std::cout << "Test 1: Energy depletion" << std::endl;
//     depleteEnergy(c1, "Target", "ClapTrap");

//     // Try attacking with no energy
//     std::cout << "Attempting attack with no energy:" << std::endl;
//     c1.attack("Enemy");

//     // Test 2: HP depletion
//     std::cout << "\nTest 2: Hit points depletion" << std::endl;
//     std::cout << "Dealing fatal damage to ClapTrap:" << std::endl;
//     c2.takeDamage(20); // More than max HP

//     // Try actions when dead
//     std::cout << "Attempting actions when dead:" << std::endl;
//     c2.attack("Enemy");
//     c2.beRepaired(5);
//     c2.takeDamage(5);

//     // Test 3: Repair with no energy
//     std::cout << "\nTest 3: Repair with no energy" << std::endl;
//     c1.beRepaired(5); // Should fail since no energy

//     // ================= SCAVTRAP TESTS =================
//     printTestHeader("SCAVTRAP BASIC TESTS");

//     // Test constructors
//     std::cout << "Testing ScavTrap constructors:" << std::endl;
//     ScavTrap s1("Guardian");
//     ScavTrap s2(s1); // Test copy constructor
//     ScavTrap s3("Sentinel");
//     s3 = s1; // Test assignment operator

//     // Basic functionality
//     std::cout << "\nTesting basic ScavTrap functionality:" << std::endl;
//     s1.attack("Enemy");
//     s1.takeDamage(15);
//     s1.beRepaired(10);
//     s1.guardGate();

//     // Edge cases
//     printTestHeader("SCAVTRAP EDGE CASES");

//     // Test 1: Heavy damage but not fatal
//     std::cout << "Test 1: Heavy damage but not fatal" << std::endl;
//     s1.takeDamage(80);
//     s1.attack("Enemy"); // Should still work
//     s1.beRepaired(30);

//     // Test 2: Energy depletion
//     std::cout << "\nTest 2: Energy depletion" << std::endl;
//     depleteEnergy(s3, "Target", "ScavTrap");

//     // Test guardGate with no energy
//     std::cout << "Testing guardGate with no energy:" << std::endl;
//     s3.guardGate(); // Should still work as it doesn't require energy

//     // Test 3: Fatal damage
//     std::cout << "\nTest 3: Fatal damage" << std::endl;
//     s2.takeDamage(200); // More than max HP
//     s2.attack("Enemy"); // Should fail
//     s2.guardGate();     // Should still work as it doesn't check HP

//     // ================= FRAGTRAP TESTS =================
//     printTestHeader("FRAGTRAP BASIC TESTS");

//     // Test constructors
//     std::cout << "Testing FragTrap constructors:" << std::endl;
//     FragTrap f1("Bomber");
//     FragTrap f2(f1); // Test copy constructor
//     FragTrap f3("Blaster");
//     f3 = f1; // Test assignment operator

//     // Basic functionality
//     std::cout << "\nTesting basic FragTrap functionality:" << std::endl;
//     f1.attack("Enemy");
//     f1.takeDamage(25);
//     f1.beRepaired(15);
//     f1.highFivesGuys();

//     // Edge cases
//     printTestHeader("FRAGTRAP EDGE CASES");

//     // Test 1: Energy depletion
//     std::cout << "Test 1: Energy depletion" << std::endl;
//     depleteEnergy(f1, "Target", "FragTrap");

//     // Try high fives with no energy
//     std::cout << "Testing highFivesGuys with no energy:" << std::endl;
//     f1.highFivesGuys(); // Should still work as it doesn't require energy

//     // Test 2: Fatal damage
//     std::cout << "\nTest 2: Fatal damage" << std::endl;
//     f2.takeDamage(150); // More than max HP
//     f2.attack("Enemy"); // Should fail
//     f2.highFivesGuys(); // Should still work as it doesn't check HP

//     // Test 3: Polymorphism
//     printTestHeader("POLYMORPHISM TESTS");

//     ClapTrap* polyTrap = new FragTrap("PolyFrag");
//     std::cout << "Attacking with polymorphic trap:" << std::endl;
//     polyTrap->attack("Target"); // Should use ClapTrap's attack since
//     FragTrap
//                                 // doesn't override it
//     polyTrap->takeDamage(50);
//     polyTrap->beRepaired(20);
//     // Note: We can't call highFivesGuys() on polyTrap without casting
//     delete polyTrap;

//     // Test object destruction
//     printTestHeader("OBJECT DESTRUCTION");
//     std::cout << "Ending test - all objects will be destroyed.\n" <<
//     std::endl;

//     return 0;
// }
