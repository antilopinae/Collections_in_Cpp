#include <iostream>

template <class T> class Sequence{
private:

public:
    T GetFirst();
    T GetLast();
    T Get(int index);
    Sequence<T>* GetSubsequence(int startIndex, int endIndex);
    int GetLength();
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int index);
    void Concat(Sequence <T> *list);
};

template <class T> class Iterable{
private:

public:

};

template <class T> class MutableIterable: Iterable<T>{
private:

public:

};

template <class T> class Collection: Iterable<T>{
private:

public:

};

template <class T> class MutableCollection: Collection<T>, MutableIterable<T>{
private:

public:

};

//иммутабельность
template <class T> class LinkedList: Collection<T>{
private:

public:
    LinkedList (T* items, int count);
    LinkedList ();
    LinkedList (LinkedList <T> & list const);
    T GetFirst();
    T GetLast();
    T Get(int index);
    LinkedList<T>* GetSubList(int startIndex, int endIndex);
    int GetLength();
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int index);
    void Concat(LinkedList<T> *list);
};

template <class T> class MutableLinkedList: LinkedList<T>, MutableCollection<T>{
private:

public:
    LinkedList (T* items, int count);
    LinkedList ();
    LinkedList (LinkedList <T> & list const);
    T GetFirst();
    T GetLast();
    T Get(int index);
    LinkedList<T>* GetSubList(int startIndex, int endIndex);
    int GetLength();
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int index);
    LinkedList<T>* Concat(LinkedList<T> *list);
};

//иммутабельность
template <class T> class DynamicArray: Collection<T>{
private:
public:
    DynamicArray(T* items, int count);
    DynamicArray(T* items, int count);
    DynamicArray(DynamicArray<T> & dynamicArray const);
    T Get(int index);
    int GetSize();
    void Set(int index, T value);
    void Resize(int index, T value);
};

template <class T> class MutableDynamicArray: DynamicArray<T>, MutableCollection<T>{
private:
public:
    DynamicArray(T* items, int count);
    DynamicArray(T* items, int count);
    DynamicArray(DynamicArray<T> & dynamicArray const);
    T Get(int index);
    int GetSize();
    void Set(int index, T value);
    void Resize(int index, T value);
};

template <class T> class ArraySequence: MutableDynamicArray<T>{
private:
    DynamicArray<T> _array;
public:
    ArraySequence (T* items, int count);
    ArraySequence();
    ArraySequence (LinkedList <T> & list const);
    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex);
    ArraySequence<T>* Append(T item);
    ArraySequence<T>* Prepend(T item);
    ArraySequence<T>* InsertAt(T item, int index);
};

template <class T> class ListSequence: MutableLinkedList<T>{
private:
    LinkedList<T> _list;
public:
    ListSequence (T* items, int count);
    ListSequence ();
    ListSequence (LinkedList <T> & list const);
    ListSequence<T>* GetSubsequence(int startIndex, int endIndex);
    ListSequence<T>* Append(T item);
    ListSequence<T>* Prepend(T item);
    ListSequence<T>* InsertAt(T item, int index);
};

int main() {

    return 0;
}
