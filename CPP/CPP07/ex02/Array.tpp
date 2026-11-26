#include "Array.hpp"


template <typename T>
Array<T>::Array() : arr(NULL), length(0) {

}

template <typename T>
Array<T>::Array(unsigned int n) : arr(NULL), length(n) {
    if (n > 0)
        arr = new T[n]();  
}

template <typename T>
Array<T>::Array(const Array& other) : arr(NULL), length(other.length) {
    if (length > 0) {
        arr = new T[length]();
        for (unsigned int i = 0; i < length; i++)
            arr[i] = other.arr[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] arr;
        length = other.length;
        if (length > 0) {
            arr = new T[length]();
            for (unsigned int i = 0; i < length; i++)
                arr[i] = other.arr[i];
        } 
        else
            arr = NULL;
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= length)
        throw std::exception();
    return arr[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= length)
        throw std::exception();
    return arr[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return length;
}
