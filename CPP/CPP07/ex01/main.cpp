#include "inter.hpp"
#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    const int constArr[] = {6, 7, 8, 9, 10};

    std::cout << "Original array: ";
    inter(arr, 5, print<int>);
    std::cout << std::endl;
    std::cout << "Constant array: ";
    inter(constArr, 5, print<int>);
    std::cout << std::endl;
    std::cout << "Incrementing array elements..." << std::endl;
    inter(arr, 5, increment<int>);
    std::cout << "Incremented array: ";
    inter(arr, 5, print<int>);
    std::cout << std::endl;

    return 0;

}