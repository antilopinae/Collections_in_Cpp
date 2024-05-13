//
// Created by antilopa on 13.05.24.
//

#ifndef VECTOR_H
#define VECTOR_H

template <class T>
struct vector{
    T element;
    vector<T>* next;
    vector<T>* prev;
    vector(vector<T>* _next, const T _element, vector<T>* _prev){
        this->next = _next;
        this->element = T{_element};
        this->prev=_prev;
    }
};

#endif //VECTOR_H
