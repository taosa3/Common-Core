#include "Zombie.hpp"

int main() {
    Zombie* zombie1 = newZombie("Zombie1");
    zombie1->announce();

    Zombie* zombie2 = newZombie("Zombie2");
    zombie2->announce();

    randomChump("Zombie3");

    delete zombie1;
    delete zombie2;

    return 0;
}