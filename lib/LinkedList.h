//
// Created by antilopa on 12.05.24.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Collection.h"

template <class T>
class LinkedList: Collection<T>{
private:

public:
    LinkedList (T* const items, int count);
    LinkedList ();
    LinkedList (LinkedList <T> * const list );
    T GetFirst();
    T GetLast();
    T Get(int index);
    LinkedList<T>* GetSubList(int startIndex, int endIndex);
    int GetLength();
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int index);
    void Concat(LinkedList<T> * const list);
};

#endif //LINKED_LIST_H
