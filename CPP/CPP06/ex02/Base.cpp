#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

Base::~Base() {
}

Base *generate(void) {
    int random = rand() % 3;
    if (random == 0) {
        return new A();
    } 
    else if (random == 1) {
        return new B();
    }
    return new C();
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } 
    else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } 
    else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } 
    else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base &p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } 
    catch (std::exception &) {}
    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } 
    catch (std::exception &) {}
    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } 
    catch (std::exception &) {
        std::cout << "Unknown type" << std::endl;
    }
}