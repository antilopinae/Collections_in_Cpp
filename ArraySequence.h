//
// Created by antilopa on 12.05.24.
//

#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H

#include "MutableDynamicArray.h"

template <class T> class ArraySequence: protected MutableDynamicArray<T>{
public:
    ArraySequence (T* items, int count);
    ArraySequence();
    ArraySequence (ArraySequence <T> * const list);
    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex);
    ArraySequence<T>* Append(T item);
    ArraySequence<T>* Prepend(T item);
    ArraySequence<T>* InsertAt(T item, int index);
};

#endif // ARRAY_SEQUENCE_H
