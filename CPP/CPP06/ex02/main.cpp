#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    Base *ptr = generate();
    identify(ptr);
    std::cout << "Identifying by pointer: ";
    identify(ptr);
    std::cout << "Identifying by reference: "; 
    identify(*ptr);
    delete ptr;
}