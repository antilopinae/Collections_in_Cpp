//
// Created by antilopa on 12.05.24.
//

#ifndef MUTABLE_DYNAMIC_ARRAY
#define MUTABLE_DYNAMIC_ARRAY

#include <cstdlib>
#include "DynamicArray.h"

template <class T>
class ArraySequence: public virtual Sequence<T>{
private:
    size_t length;
    size_t capacity;
    size_t top = 0;
    DynamicArray<T> array = DynamicArray<T>(capacity);
    T getElement(size_t index){
        return T{this->array.GetArrayPtr()[index]};
    };
    void resize(size_t _size){
        if(_size>capacity){
            array.Realloc(_size);
            T* array_p = array.GetArrayPtr();
            for(size_t i = top; i<0; ++i){
                array_p[_size+top] = array_p[capacity+top];
            }
            capacity = _size;
        }
    };
    void checkAndAddFreeSpace(size_t add_size){
        checkAndAddFreeSpace(add_size, length / 2);
    };
    void checkAndAddFreeSpace(size_t add_size, size_t add_capacity){
        if(add_size+length>capacity){
            resize(length+add_size+add_capacity);
        }
    };
public:
    ArraySequence(T* items, size_t count){
        length = count;
        capacity = length*2 + length/2;
        T* ptr = array.GetArrayPtr();
        for(size_t i = 0; i < count; ++i){
            ptr[i] = T{items[i]};
        }
    };
    ArraySequence(const ArraySequence<T> &arraySequence):
        ArraySequence(
            arraySequence.array.GetArrayPtr(),
            arraySequence.size
        ){};
    T GetFirst() override final{
        size_t index = top>0?capacity-top:0;
        return getElement(index);
    };
    T GetLast() override final{
        return getElement(length-top-1);
    };
    T Get(size_t index) override final{
        if(index>length-1) throw "Index out of bounds";
        if(index<top) index = capacity+index-top;
        return getElement(index);
    };
    size_t GetLength() override final{
        return length;
    };
    void Append(T item) override final{
        checkAndAddFreeSpace(1);
        array.GetArrayPtr()[length-top] = T{item};
        ++length;
    };
    void Prepend(T item) override final{
        checkAndAddFreeSpace(1);
        array.GetArrayPtr()[capacity-top] = T{item};
        ++length;
        ++top;
    };
    void InsertAt(T item, size_t index) override final{
        if(index>length-1) throw "Index out of bounds";
        Delete(index);
        if(index<top) index = capacity+index-top;
        array.GetArrayPtr()[index] = T{item};
    };
    void Delete(size_t index) override final{
        if(index>length-1) throw "Index out of bounds";
        T* array_p = array.GetArrayPtr();
        if(index<top) {
            for(size_t i=capacity-top; i<=index; ++i){
                array_p[i] = array_p[i-1];
            }
            --top;
            --length;
        }
        else{
            index = index - top;
            for(size_t i=index; i<length-top; ++i){
                array_p[i] = array_p[i+1];
            }
            --length;
        }
    };
    void DeleteCollection() override final{
        array.Delete();
    };
    void Concat(Sequence <T> * const list) override final{
        size_t _length = list->GetLength();
        checkAndAddFreeSpace(_length);
        for(int i=0; i<_length; ++i){
            --_length;
            this->Append(T{list->Get(i)});
        }
    };
    ~ArraySequence(){
        DeleteCollection();
    };
};


#endif // MUTABLE_DYNAMIC_ARRAY
