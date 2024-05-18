//
// Created by antilopa on 13.05.24.
//

#ifndef MUTABLE_STACK_H
#define MUTABLE_STACK_H

#include "Queue.h"
#include <cstdlib>

template <typename T>
class MutableStack: public Queue<T>{
private:
    LinkedList<T>* _collection = new LinkedList<T>();
protected:
    Queue<T>* Push(T item) const override final{
        const MutableStack<T>* mutableStack{this};
        mutableStack->Push(item);
        return const_cast<MutableStack<T>*>(mutableStack);
    };
    Queue<T>* GetSubQueue(size_t depth) const override final{
        const MutableStack<T>* mutableStack{this};
        mutableStack->GetSubQueue(depth);
        return const_cast<MutableStack<T>*>(mutableStack);
    };
    Queue<T>* Concat(Queue<T>* const list) const override final{
        const MutableStack<T>* mutableStack{this};
        mutableStack->Concat(list);
        return const_cast<MutableStack<T>*>(mutableStack);
    };
public:
    MutableStack(): Queue<T>(){};
    MutableStack(T* items, size_t count){
        for(size_t i =0; i < count; ++i){
            this->_collection->Append(items[i]);
        }
    };
    MutableStack(const MutableStack<T>& mutableStack){
        size_t length = mutableStack.GetLength();
        for(int i=0; i<length; ++i){
            this->_collection->Append(mutableStack._collection.Get(i));
        }
    };
    T Pop() const override final{
        T element = T{_collection->GetLast()};
        return element;
    };
    T Pull() override final{
        T element = this->Pop();
        int length = _collection->GetLength();
        _collection->Delete(length-1);
        return element;
    };
    size_t GetLength() const override final{
        return _collection->GetLength();
    };
    void Push(const T item) override final{
        _collection->Append(item);
    };
    void Concat(Queue <T> * const queue) override final{
        int length = queue->GetLength();
        T element;
        for(int i=0; i<length;++i){
            element = queue->Pull();
            this->_collection->Append(T{element});
        }
    };
    Queue<T>* GetSubQueue(size_t depth){
        size_t endIndex = this->_collection->GetLength()-1;
        LinkedList<T>* sequence = this->_collection->GetSubsequence(endIndex-depth+1, endIndex);
        MutableStack<T>* stack = new MutableStack<T>();

        int size = sequence->GetLength();
        for(int i=0; i<size;++i){
            stack->Push(T{sequence->Get(i)});
        }

        for(int i=0; i<depth;++i){
            this->_collection->Delete(endIndex);
        }
        return stack;
    };
    void DeleteQueue() override final{
        _collection->DeleteList();
    };
    ~MutableStack(){
        DeleteQueue();
    };
};

#endif //MUTABLE_STACK_H
