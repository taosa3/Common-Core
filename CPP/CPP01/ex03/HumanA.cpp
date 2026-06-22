#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon) {
    this->name = name;
};

HumanA::~HumanA() {
    return ;
};

void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
};