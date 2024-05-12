#include "Iterable.h"

template <class T>
class Collection: Iterable<T>{
public:
    T GetFirst();
    T GetLast();
    T Get(int index);
    Collection<T>* GetSubsequence(int startIndex, int endIndex);
    int GetLength();
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int index);
    void Concat(Collection <T> *list);
};
