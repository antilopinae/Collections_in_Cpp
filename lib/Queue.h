//
// Created by antilopa on 17.05.24.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>

template <class T>
class Queue{
protected:
    virtual Queue<T>* Push(T item) const = 0;
    virtual Queue<T>* GetSubQueue(size_t depth) const = 0;
    virtual Queue<T>* Concat(Queue<T> * list) const = 0;
public:
    virtual T Pop() const = 0;
    virtual T Pull() = 0;
    virtual size_t GetLength() const = 0;
    virtual void Push(T item) = 0;
    virtual Queue<T>* GetSubQueue(size_t depth) = 0;
    virtual void Concat(Queue<T> * list) = 0;
    virtual void DeleteQueue() = 0;
};

#endif //QUEUE_H