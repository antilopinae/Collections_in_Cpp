//
// Created by antilopa on 12.05.24.
//

#ifndef MUTABLE_LINKED_LIST
#define MUTABLE_LINKED_LIST

#include "Collection.h"

template <class T>
class MutableLinkedList: public virtual Collection<T>{
public:
    MutableLinkedList (T* items, int count){
        for(int i = 0; i< count; ++i){
            Collection<T>::Append(items[i]);
        }
    };
    MutableLinkedList (){};
    MutableLinkedList (const MutableLinkedList <T> & list){
        Collection<T>::DeleteCollection();
        int size = list.GetLength();
        for(int i = 0; i< size; ++i){
            Collection<T>::Append(list.Get(i));
        }
    };
};

#endif // MUTABLE_LINKED_LIST
