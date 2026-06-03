#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "A new zombie has been created!" << std::endl;
}

Zombie::Zombie(std::string name) {
    this->name = name;
    std::cout << "Zombie " << name << " has been created!" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << name << " has been destroyed!" << std::endl;
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

