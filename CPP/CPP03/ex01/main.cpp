#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{   
    ClapTrap clap1("copy test");
    ClapTrap clap2 = clap1;
    clap2.attack("Another Enemy");
    

    ScavTrap scav1("Villager");
    scav1.attack("Steve");
    scav1.attack("Alex");
    scav1.takeDamage(20);
    scav1.beRepaired(10);
    scav1.guardGate();
    

    ScavTrap scav2 = scav1;
    scav2.attack("Target3");
    

    ScavTrap scav3("Energy Test");
    for (int i = 0; i < 50; i++) {
        scav3.attack("Enemy");
    }
    scav3.beRepaired(5);
    

    ClapTrap clap3("Test Dead");
    for (int i = 0; i < 15; i++) {
        clap3.takeDamage(1);
    }
    clap3.beRepaired(5);
    clap3.attack("Dead Attack");
    

    ScavTrap scav4("Gate mode test");
    scav4.guardGate();
    scav4.guardGate();
    scav4.takeDamage(150);
    scav4.guardGate();
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    return (0);
}