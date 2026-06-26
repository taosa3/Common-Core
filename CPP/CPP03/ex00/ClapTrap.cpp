#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "ClapTrap " << name << " cannot attack due to insufficient energy or hit points." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints > 0) {
        hitPoints -= amount;
        if (hitPoints < 0) 
            hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " is already dead and cannot take more damage." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " is repaired by " << amount << " points! New hit points: " << hitPoints << "; Energy Remaining: " << energyPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " cannot be repaired due to insufficient energy or being dead." << std::endl;
    }
}

