#include "MutableCollection.h"
#include "LinkedList.h"

template <class T>
class MutableLinkedList: LinkedList<T>, MutableCollection<T>{
private:

public:
    MutableLinkedList (T* items, int count);
    MutableLinkedList ();
    MutableLinkedList (MutableLinkedList <T> * const list);
    T GetFirst();
    T GetLast();
    T Get(int index);
    MutableLinkedList<T>* GetSubList(int startIndex, int endIndex);
    int GetLength();
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int index);
    MutableLinkedList<T>* Concat(MutableLinkedList<T> * const list);
};
