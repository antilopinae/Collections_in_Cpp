//
// Created by antilopa on 12.05.24.
//

#ifndef MUTABLE_DYNAMIC_ARRAY
#define MUTABLE_DYNAMIC_ARRAY

#include "Collection.h"

template <class T>
class DynamicArray: private virtual Collection<T>{
protected:
    void Delete(int index) const override final{
        Collection<T>::Delete(index);
    }
    void DeleteCollection() const override final{
        Collection<T>::DeleteCollection();
    }
public:
    DynamicArray(T* items, int count){
        for(int i = 0; i< count; ++i){
            Collection<T>::Append(T{items[i]});
        }
    };
    DynamicArray(const DynamicArray<T> &dynamicArray){
        int length = dynamicArray.GetLength();
        Collection<T>::DeleteCollection();
        for(int i = 0; i< length; ++i){
            Collection<T>::Append(T{dynamicArray.Get(i)});
        }
    };
    T GetFirst() const override final{
        T element = Collection<T>::GetFirst();
        return T{element};
    };
    T GetLast() const override final{
        T element = Collection<T>::GetLast();
        return T{element};
    };
    T Get(int index) const override final{
        T element = Collection<T>::Get(index);
        return T{element};
    };
    int GetLength() const override final{
        return Collection<T>::GetLength();
    };
};



#endif // MUTABLE_DYNAMIC_ARRAY
