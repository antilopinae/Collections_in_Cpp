//
// Created by antilopa on 13.05.24.
//

#ifndef LAB2_MUTABLESTACK_H
#define LAB2_MUTABLESTACK_H

#include "LinkedList.h"
//
//template <typename T>
//class MutableStack: public Sequence<T>{
//private:
//    LinkedList<T> _collection = LinkedList<T>();
//    void Prepend(const T item) const override{};
//    void InsertAt(const T item, int index) const override{};
//    void Delete(int index) const override{};
//    T GetFirst() const override{};
//    T Get(int index) const override{};
//public:
//    MutableStack<T>(){};
//    T GetLast() const override final{
//        int length = _collection.GetLength();
//        T element = T{_collection.GetLast()};
//        _collection.Delete(length-1);
//        return element;
//    };
//    int GetLength() const override final{
//        return _collection.GetLength();
//    };
//    void Append(const T item) const override final{
//        _collection.Append(item);
//    };
//    void DeleteCollection() const override final{
//        _collection.DeleteCollection();
//    };
//    void Concat(MutableStack <T> * const list){
//        int length = list->GetLength();
//        T element;
//        for(int i=0; i<length;++i){
//            element = list->_collection.Get(i);
//            _collection.Append(T{element});
//        }
//    };
//    MutableStack<T>* GetSubsequence(int startIndex, int endIndex){
//        LinkedList<T>* sequence = _collection.GetSubsequence(startIndex, endIndex);
//        MutableStack<T>* stack = new MutableStack<T>();
//
//        int size = sequence->GetLength();
//        for(int i=0; i<size;++i){
//            stack->Append(T{sequence->Get(i)});
//        }
//
//        for(int i=startIndex; i<endIndex;++i){
//            _collection.Delete(startIndex);
//        }
//        return stack;
//    };
//    ~MutableStack<T>(){
//        _collection.DeleteCollection();
//    };
//};

#endif //LAB2_MUTABLESTACK_H
