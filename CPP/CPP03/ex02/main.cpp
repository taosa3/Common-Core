#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{   
    ClapTrap clap1("copy test");
    ClapTrap clap2 = clap1;
    clap2.attack("Another Enemy");
    

    FragTrap frag1("FragTrap inheritance test");
    frag1.attack("Steve");
    frag1.attack("Alex");
    frag1.takeDamage(20);
    frag1.beRepaired(10);
    frag1.highFivesGuys();
    

    FragTrap frag2 = frag1;
    frag2.attack("Target3");
    

    FragTrap frag3("Energy Test");
    for (int i = 0; i < 50; i++) {
        frag3.attack("Enemy");
    }
    frag3.beRepaired(5);
    

    ClapTrap clap3("Test Dead");
    for (int i = 0; i < 15; i++) {
        clap3.takeDamage(1);
    }
    clap3.beRepaired(5);
    clap3.attack("Dead Attack");
    

    FragTrap frag4("Gate mode test");
    frag4.highFivesGuys();
    frag4.highFivesGuys();
    frag4.takeDamage(150);
    frag4.highFivesGuys();
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    return (0);
}