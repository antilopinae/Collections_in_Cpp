#include "Collection.h"

//иммутабельность
template <class T>
class DynamicArray: Collection<T>{
private:
public:
    DynamicArray(T* items, int count);
    DynamicArray(const DynamicArray<T>& dynamicArray);
    T Get(int index);
    int GetSize();
    void Set(int index, T value);
    void Resize(int index, T value);
};
