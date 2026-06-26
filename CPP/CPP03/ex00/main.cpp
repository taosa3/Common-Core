#include "ClapTrap.hpp"

int main()
{
    ClapTrap Light("light");
    ClapTrap Dark("dark");
    ClapTrap a = Light;
    Light.attack("dark");
    Dark.takeDamage(5);
    Dark.attack("light");
    Light.takeDamage(7);
    Dark.beRepaired(5);
    Light.beRepaired(3);
    Dark.attack("light");
    Light.takeDamage(10);
    Light.takeDamage(5);
    Dark.beRepaired(1);
    Dark.beRepaired(1);
    Dark.beRepaired(1);
    Dark.beRepaired(1);
    Dark.beRepaired(1);
    Dark.beRepaired(1);
    Dark.beRepaired(1);
    Dark.beRepaired(1);

}