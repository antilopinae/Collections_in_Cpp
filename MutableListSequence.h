//
// Created by antilopa on 12.05.24.
//

#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H

#include "MutableLinkedList.h"
#include "Iterable.h"

template <class T>
class MutableListSequence: public Iterable<T>{
private:
    MutableLinkedList<T> _list = MutableLinkedList<T>();
public:
    MutableListSequence (T* items, int count){
        for(int i =0; i < count; ++i){
            _list.Append(items[i]);
        }
    };
    MutableListSequence (){};
    T GetFirst() const override final{
        return _list.GetFirst();
    };
    T GetLast() const override final{
        return _list.GetLast();
    };
    T Get(int index) const override final{
        return _list.Get(index);
    };
    int GetLength() const override final{
        return _list.GetLength();
    };
    void Append(const T item) const override final{
        _list.Append(item);
    };
    void Prepend(const T item) const override final{
        _list.Prepend(item);
    };
    void InsertAt(const T item, int index) const override final{
        _list.InsertAt(item, index);
    };
    void Delete(int index) const override final{
        _list.Delete(index);
    }
    void DeleteCollection() const override final{
        _list.DeleteCollection();
    }
};

#endif // LIST_SEQUENCE_H
