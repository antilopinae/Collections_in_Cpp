//
// Created by antilopa on 12.05.24.
//

#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H

#include "DynamicArray.h"

template <class T> class ArraySequence: public Iterable<T>{
    DynamicArray<T> _array;
private:
    void Delete(int index) const override final{
        // nothing to do;
    };
    void DeleteCollection() const override final{
        // nothing to do;
    };
    void Append(const T item) const override final{
//        _array.Append(item);
    };
    void Prepend(const T item) const override final{
//        _array.Prepend(item);
    };
    void InsertAt(const T item, int index) const override final{
//        _array.InsertAt(item, index);
    };
public:
    ArraySequence (T* items, int count) :_array(DynamicArray(items, count)){};

    T GetFirst() const override final{
        return _array.GetFirst();
    };
    T GetLast() const override final{
        return _array.GetLast();
    };
    T Get(int index) const override final{
        return _array.Get(index);
    };
    int GetLength() const override final{
        return _array.GetLength();
    };
};



#endif // ARRAY_SEQUENCE_H
