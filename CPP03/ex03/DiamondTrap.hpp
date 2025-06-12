#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include <iostream>

class DiamondTrap
{
    public:
        DiamondTrap(void);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap &operator=(const DiamondTrap &other);
        ~DiamondTrap();
};

#endif

