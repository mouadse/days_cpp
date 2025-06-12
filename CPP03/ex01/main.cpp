#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int
main()
{
    std::cout << "=== Stack-allocated ScavTrap ===" << std::endl;
    {
        ScavTrap serena("Serena");

        serena.attack("the target");

        serena.takeDamage(30);
        serena.beRepaired(20);

        serena.guardGate();
    }

    std::cout << "\n=== Dynamic ScavTrap ===" << std::endl;
    {
        ScavTrap* lineWorker = new ScavTrap("LineWorker");
        lineWorker->attack("an enemy");
        delete lineWorker;
    }

    return 0;
}
/*
int
main()
{
    std::cout << "=== Testing ClapTrap ===" << std::endl;
    {
        ClapTrap defaultCT;
        ClapTrap namedCT("Bob");
        ClapTrap copyCT(namedCT); // copy constructor
        ClapTrap assignCT;
        assignCT = namedCT; // copy assignment

        std::cout << "-- Attack tests --" << std::endl;
        namedCT.attack("Dummy"); // normal attack
        // deplete energy points
        for (int i = 0; i < 11; ++i)
            namedCT.attack("Dummy");

        std::cout << "-- Hit point zero attack --" << std::endl;
        copyCT.takeDamage(100);      // kill
        copyCT.attack("ShouldFail"); // no hit points

        std::cout << "-- TakeDamage edge cases --" << std::endl;
        defaultCT.takeDamage(5);
        defaultCT.takeDamage(5);
        defaultCT.takeDamage(1); // below zero test

        std::cout << "-- Repair tests --" << std::endl;
        assignCT.beRepaired(10); // normal repair
        // deplete energy points for repairs
        for (int i = 0; i < 11; ++i)
            assignCT.beRepaired(1);

        std::cout << std::endl;
    }

    std::cout << "=== Testing ScavTrap ===" << std::endl;
    {
        ScavTrap scav("Alice");
        ScavTrap scavCopy(scav); // copy constructor
        ScavTrap scavAssign("Temp");
        scavAssign = scav;       // copy assignment

        std::cout << "-- GuardGate --" << std::endl;
        scav.guardGate(); // special mode

        std::cout << "-- Attack tests --" << std::endl;
        scav.attack("Enemy"); // normal attack
        for (int i = 0; i < 51; ++i)
            scav.attack("Enemy");

        std::cout << "-- Damage and repair edge cases --" << std::endl;
        scav.takeDamage(20);
        scav.beRepaired(5);
        scav.takeDamage(200); // kill
        scav.beRepaired(10);  // repair on dead should fail
        scav.attack("NoOne"); // attack on dead should fail

        std::cout << std::endl;
    }

    return 0;
}
*/
