#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    this->type = type;
}

Weapon::~Weapon() {
    std::cout << "Weapon destroyed!" << std::endl;
}

const std::string& Weapon::getType() const {
    return type;
}

void Weapon::setType(std::string newtype) {
    type = newtype;
}
