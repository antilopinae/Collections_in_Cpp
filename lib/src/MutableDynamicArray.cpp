#include "DynamicArray.h"
#include "MutableCollection.h"

template <class T>
class MutableDynamicArray: DynamicArray<T>, MutableCollection<T>{
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
