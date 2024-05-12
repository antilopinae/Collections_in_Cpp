//
// Created by antilopa on 12.05.24.
//

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "Collection.h"

template <class T>
class DynamicArray: protected Collection<T>{
private:
public:
    DynamicArray(T* items, int count);
    DynamicArray(const DynamicArray<T>& dynamicArray);
    T Get(int index);
    int GetSize();
    void Set(int index, T value);
    void Resize(int index, T value);
};

#endif // DYNAMIC_ARRAY_H
