//
// Created by antilopa on 14.05.24.
//

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstdlib>
#include "Exception.h"

template <typename T>
class DynamicArray {
private:
    T *array_ptr;
public:
    DynamicArray(size_t size);
    T* GetArrayPtr();
    void Malloc(size_t size);
    void Realloc(size_t size);
    void Delete();
    ~DynamicArray();
};

template <typename T>
DynamicArray<T>::DynamicArray(size_t size) {
    Malloc(size);
}

template <typename T>
T *DynamicArray<T>::GetArrayPtr() {
    return array_ptr;
}

template <typename T>
void DynamicArray<T>::Delete() {
    if(!array_ptr){
        delete[] array_ptr;
        array_ptr = nullptr;
    }
};

template <typename T>
void DynamicArray<T>::Malloc(size_t size) {
    array_ptr = {new T[size]};
};

template <typename T>
void DynamicArray<T>::Realloc(size_t size) {
    if(!array_ptr) throw IllegalException("Null pointer Exception!");
    int * _ptr =(int*) realloc((void*)array_ptr, size);
    if(!_ptr) throw IllegalException("Malloc exception in dynamic array");
    delete[] array_ptr;
    array_ptr = _ptr;
};

template <typename T>
DynamicArray<T>::~DynamicArray() {
    if(!array_ptr) this->Delete();
};

#endif //DYNAMIC_ARRAY_H
