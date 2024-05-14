//
// Created by antilopa on 12.05.24.
//

#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H

#include <cstdlib>
#include "Sequence.h"

template <class T>
class ListSequence: public virtual Sequence<T>{
private:
    LinkedList<T> _list = LinkedList<T>();
public:
    ListSequence (): Sequence<T>(){};
    ListSequence (void (*print_element)(T element)): Sequence<T>(print_element){};
    ListSequence (T* items, size_t count){
        for(size_t i =0; i < count; ++i){
            _list.Append(items[i]);
        }
    };
    ListSequence (const LinkedList <T> & list){
        Sequence<T>::DeleteCollection();
        size_t size = list.GetLength();
        for(size_t i = 0; i< size; ++i){
            Sequence<T>::Append(list.Get(i));
        }
    };
    T GetFirst() override final{
        return _list.GetFirst();
    };
    T GetLast() override final{
        return _list.GetLast();
    };
    T Get(size_t index) override final{
        return _list.Get(index);
    };
    size_t GetLength() override final{
        return _list.GetLength();
    };
    void Append(const T item) override final{
        _list.Append(item);
    };
    void Prepend(const T item) override final{
        _list.Prepend(item);
    };
    void InsertAt(const T item, size_t index) override final{
        _list.InsertAt(item, index);
    };
    void Delete(size_t index) override final{
        _list.Delete(index);
    }
    void DeleteCollection() override final{
        _list.DeleteList();
    }
    void Concat(Sequence <T> * const list) override final{

    };
};

#endif // LIST_SEQUENCE_H
