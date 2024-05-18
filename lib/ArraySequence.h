//
// Created by antilopa on 12.05.24.
//

#ifndef ARRAY_SEQUENCE
#define ARRAY_SEQUENCE

#include <cstdlib>
#include "DynamicArray.h"
#include "Exception.h"

template <class T>
class ArraySequence: public virtual Sequence<T>{
private:
    size_t length;
    size_t capacity;
    size_t top;
    DynamicArray<T> array = DynamicArray<T>(capacity);
    T getElement(size_t index){
        return T{array.GetArrayPtr()[index]};
    };
    void resize(size_t _size){
        if(_size>capacity){
            array.Realloc(_size);
            T* array_p = array.GetArrayPtr();
            for(size_t i = 0; i<top; ++i){
                array_p[_size-top+i] = array_p[capacity-top+i];
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
protected:
    Sequence<T>* Append(T item) const override{
        const ArraySequence<T>* arraySequence{this};
        arraySequence->Append(item);
        return const_cast<ArraySequence<T>*>(arraySequence);
    };
    Sequence<T>* Prepend(T item) const override{
        const ArraySequence<T>* arraySequence{this};
        arraySequence->Prepend(item);
        return const_cast<ArraySequence<T>*>(arraySequence);
    };
    Sequence<T>* InsertAt(T item, size_t index) const override{
        const ArraySequence<T>* arraySequence{this};
        arraySequence->InsertAt(item, index);
        return const_cast<ArraySequence<T>*>(arraySequence);
    };
    Sequence<T>* Delete(size_t index) const override{
        const ArraySequence<T>* arraySequence{this};
        arraySequence->Delete(index);
        return const_cast<ArraySequence<T>*>(arraySequence);
    };
    Sequence<T>* Concat(Sequence <T> * const list) const override{
        const ArraySequence<T>* arraySequence{this};
        arraySequence->Concat(list);
        return const_cast<ArraySequence<T>*>(arraySequence);
    };
    Sequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) const override{
        const ArraySequence<T>* arraySequence{this};
        arraySequence->GetSubsequence(startIndex, endIndex);
        return const_cast<ArraySequence<T>*>(arraySequence);
    };
public:
    ArraySequence(){
        length=0;
        capacity=2;
        top=0;
    };
    ArraySequence(size_t size){
        length=0;
        capacity = size*2 + size/2;
        top=0;
    };
    ArraySequence(T* items, size_t count){
        length = count;
        capacity = length*2 + length/2;
        T* ptr = array.GetArrayPtr();
        for(size_t i = 0; i < count; ++i){
            ptr[i] = T{items[i]};
        }
        top=0;
    };
    ArraySequence(const ArraySequence<T> &arraySequence):
        ArraySequence(
            arraySequence.array.GetArrayPtr(),
            arraySequence.size
        ){};
    T GetFirst() override final{
        size_t index;
        if(top>0){
            index = capacity-top;
        }else{
            index = 0;
        }
        return getElement(index);
    };
    T GetLast() override final{
        return getElement(length-top-1);
    };
    T Get(size_t index) override final{
        if(index>length-1) throw IndexOutOfBoundsException("Index out of bounds");
        if(index<top) {
            index = capacity+index-top;
        }
        else{
            index = index-top;
        }
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
        array.GetArrayPtr()[capacity-top-1] = T{item};
        ++length;
        ++top;
    };
    void InsertAt(T item, size_t index) override final{
        if(index>length-1) throw IndexOutOfBoundsException("Index out of bounds");
        T* array_p = array.GetArrayPtr();
        if(index<top) {
            index = capacity-top+index;
            for(size_t i=capacity-top; i<=index; ++i){
                array_p[i+1] = array_p[i];
            }

        }
        else{
            index = index - top;
            for(size_t i=index; i<length-top; ++i){
                array_p[i] = array_p[i+1];
            }
        }
        array.GetArrayPtr()[index] = T{item};
    };
    void Delete(size_t index) override final{
        if(index>length-1) throw IndexOutOfBoundsException("Index out of bounds");
        T* array_p = array.GetArrayPtr();
        if(index<top) {
            index = capacity-top+index;
            for(size_t i=capacity-top; i<=index; ++i){
                array_p[i+1] = array_p[i];
            }
            --top;
        }
        else{
            index = index - top;
            for(size_t i=index; i<length-top; ++i){
                array_p[i] = array_p[i+1];
            }
        }
        --length;
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
    Sequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) override final{
        if(startIndex>endIndex) throw IllegalIndex("Illegal index Exception");
        if(startIndex>=length || endIndex>=length) throw IndexOutOfBoundsException("Index out of bounds Exception");
        ArraySequence<T>* arraySequence = new ArraySequence<T>(endIndex-startIndex);
        for(size_t i=startIndex; i<=endIndex; i++){
            arraySequence->Append(T{this->Get(startIndex)});
            this->Delete(startIndex);
        }
        return arraySequence;
    };
    ~ArraySequence(){
        DeleteCollection();
    };
};


#endif // ARRAY_SEQUENCE
