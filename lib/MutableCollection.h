//
// Created by antilopa on 12.05.24.
//

#ifndef MUTABLE_COLLECTION_H
#define MUTABLE_COLLECTION_H

#include "Collection.h"
#include "MutableIterable.h"

template <class T>
class MutableCollection: public Collection<T>, public virtual MutableIterable<T>{
private:

public:

};

#endif // MUTABLE_COLLECTION_H
