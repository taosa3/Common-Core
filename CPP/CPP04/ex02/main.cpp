#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    delete j;
    delete i;

    const WrongAnimal* wrong = new WrongCat();
    wrong->makeSound();
    delete wrong;

    std::cout << std::endl;
	int size = 4;
	Animal* animals[size];
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "========Animal Array========" << std::endl;
    for (int i = 0; i < size; i++) {
        animals[i]->makeSound();
    }
    for (int i = 0; i < size; i++) {
        delete animals[i];
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "========Brain Test========" << std::endl;
    Cat a1;
    Cat a2 = a1;
    a1.getBrain()->ideas[0] = "I want to eat fish";
    a2.getBrain()->ideas[0] = "I want to scratch you!";
    std::cout << "a1's brain idea: " << a1.getBrain()->ideas[0] << std::endl;
    std::cout << "a2's brain idea: " << a2.getBrain()->ideas[0] << std::endl;

    //Animal *animal = nwe Animal();
    //delete animal;
    return 0;
}