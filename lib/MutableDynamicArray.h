//
// Created by antilopa on 12.05.24.
//

#ifndef MUTABLE_DYNAMIC_ARRAY
#define MUTABLE_DYNAMIC_ARRAY

#include "DynamicArray.h"
#include "MutableCollection.h"

template <class T>
class MutableDynamicArray: public DynamicArray<T>, public virtual MutableCollection<T>{
private:
public:
    MutableDynamicArray(T* items, int count);
    MutableDynamicArray();
    MutableDynamicArray(MutableDynamicArray<T> * const dynamicArray);
    T Get(int index);
    int GetSize();
    void Set(int index, T value);
    void Resize(int index, T value);
};

#endif // MUTABLE_DYNAMIC_ARRAY
