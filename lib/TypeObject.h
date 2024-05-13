//
// Created by antilopa on 13.05.24.
//

#ifndef OBJECT_H
#define OBJECT_H

template <class T>
class TypeObject{
private:
    T* _element;
    bool _isEmpty = true;
public:
    bool isEmpty(){
        return _isEmpty;
    };
    void initialize(T* element){
        _element = element;
        _isEmpty = false;
    };
    T* getElement(){
        if(!_isEmpty){
            return _element;
        }
        else throw "TypeObject is empty!";
    };
};

#endif //OBJECT_H
