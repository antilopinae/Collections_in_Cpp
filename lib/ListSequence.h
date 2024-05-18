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
protected:
    Sequence<T>* Append(T item) const override{
        const ListSequence<T>* listSequence{this};
        listSequence->Append(item);
        return const_cast<ListSequence<T>*>(listSequence);
    };
    Sequence<T>* Prepend(T item) const override{
        const ListSequence<T>* listSequence{this};
        listSequence->Prepend(item);
        return const_cast<ListSequence<T>*>(listSequence);
    };
    Sequence<T>* InsertAt(T item, size_t index) const override{
        const ListSequence<T>* listSequence{this};
        listSequence->InsertAt(item, index);
        return const_cast<ListSequence<T>*>(listSequence);
    };
    Sequence<T>* Delete(size_t index) const override{
        const ListSequence<T>* listSequence{this};
        listSequence->Delete(index);
        return const_cast<ListSequence<T>*>(listSequence);
    };
    Sequence<T>* Concat(Sequence <T> * const list) const override{
        const ListSequence<T>* listSequence{this};
        listSequence->Concat(list);
        return const_cast<ListSequence<T>*>(listSequence);
    };
    Sequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) const override{
        const ListSequence<T>* listSequence{this};
        listSequence->GetSubsequence(startIndex, endIndex);
        return const_cast<ListSequence<T>*>(listSequence);
    };
public:
    ListSequence (): Sequence<T>(){};
    ListSequence (T* items, size_t count){
        for(size_t i =0; i < count; ++i){
            _list.Append(items[i]);
        }
    };
    ListSequence (const ListSequence <T> & list){
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
        size_t length = list->GetLength();
        for(size_t i=0; i<length; ++i){
            _list.Append(T{list->Get(i)});
        }
    };
    Sequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) override final{
        LinkedList<T>* list = _list.GetSubsequence(startIndex, endIndex);
        ListSequence<T>* listSequence = new ListSequence<T>();
        size_t length = list->GetLength();
        for(size_t i=0; i< length; ++i){
            listSequence->Append(T{list->Get(i)});
        }
//        Sequence<T> sequence{static_cast<Sequence<T>>(*listSequence)};
        return listSequence;
    };
};

#endif // LIST_SEQUENCE_H
