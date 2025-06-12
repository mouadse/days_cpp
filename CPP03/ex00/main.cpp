
#include "ClapTrap.hpp"

int
main()
{
    std::cout << "Testing ClapTrap functionality...\n";

    ClapTrap bot("TestBot");
    bot.attack("target");
    bot.takeDamage(5);
    bot.beRepaired(3);

    std::cout << "\nTesting energy depletion...\n";
    ClapTrap energyTest("EnergyBot");
    for (int i = 0; i < 11; ++i)
    {
        energyTest.attack("target");
    }

    std::cout << "\nTesting death...\n";
    ClapTrap deathTest("DeathBot");
    deathTest.takeDamage(15);
    deathTest.attack("target");

    std::cout << "\nAll tests completed.\n";

    return 0;
}
