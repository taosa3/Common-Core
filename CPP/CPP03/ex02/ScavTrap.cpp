#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default"), gateMode(false) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), gateMode(false) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "ScavTrap " << name << " cannot attack due to insufficient energy or hit points." << std::endl;
    }
}

void ScavTrap::guardGate() {
    if (hitPoints <= 0) {
        std::cout << "ScavTrap " << name << " cannot enter Gate keeper mode because it's dead." << std::endl;
        return ;
    }
    if (gateMode) {
        std::cout << "ScavTrap " << name << " is already in Gate keeper mode." << std::endl;
    } else {
        gateMode = true;
        std::cout << "ScavTrap " << name << " has entered Gate keeper mode." << std::endl;
    }
}

