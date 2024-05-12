//
// Created by antilopa on 12.05.24.
//

#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H

#include "MutableLinkedList.h"

template <class T> class ListSequence: MutableLinkedList<T>{
private:
    LinkedList<T> _list;
public:
    ListSequence (T* items, int count);
    ListSequence ();
    ListSequence (LinkedList <T> * const list);
    ListSequence<T>* GetSubsequence(int startIndex, int endIndex);
    ListSequence<T>* Append(T item);
    ListSequence<T>* Prepend(T item);
    ListSequence<T>* InsertAt(T item, int index);
};

#endif // LIST_SEQUENCE_H
