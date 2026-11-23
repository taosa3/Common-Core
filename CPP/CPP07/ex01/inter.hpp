#ifndef INTER_HPP
#define INTER_HPP

#include <iostream>

template <typename T, typename F>
void inter(T *arr, size_t size, F func)
{
    for (size_t i = 0; i < size; i++)
        func(arr[i]);
}

template <typename T>
void print(const T value) {
    std::cout << value << " ";
}

template <typename T>
void increment(T &value) {
    value++;
}

#endif