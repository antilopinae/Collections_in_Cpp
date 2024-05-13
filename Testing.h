//
// Created by antilopa on 13.05.24.
//

#ifndef TESTING_H
#define TESTING_H

#include <assert.h>
#include "Collection.h"
#include "MutableListSequence.h"
#include "ArraySequence.h"

int test() {
    Collection<int> collection1 = Collection<int>();

    collection1.Append(3);
    collection1.Prepend(2);
    collection1.InsertAt(1, 0);

    assert(collection1.GetFirst() == 1);
    assert(collection1.GetLast() == 3);
    assert(collection1.Get(0) == 1);
    assert(collection1.Get(1) == 2);
    assert(collection1.Get(2) == 3);

    Collection<int> collection2 = Collection<int>();

    collection2.Append(6);
    collection2.Prepend(4);
    collection2.InsertAt(5, 1);

    assert(collection2.GetFirst() == 4);
    assert(collection2.GetLast() == 6);
    assert(collection2.Get(0) == 4);
    assert(collection2.Get(1) == 5);
    assert(collection2.Get(2) == 6);

    collection1.Concat(&collection2);

    assert(collection1.GetFirst() == 1);
    assert(collection1.GetLast() == 6);
    assert(collection1.Get(0) == 1);
    assert(collection1.Get(1) == 2);
    assert(collection1.Get(2) == 3);
    assert(collection1.Get(3) == 4);
    assert(collection1.Get(4) == 5);
    assert(collection1.Get(5) == 6);

    assert(collection1.GetLength() == 6);

    Collection<int>* collection3 = collection1.GetSubsequence(2,5);

    assert(collection3->Get(0) == 3);
    assert(collection3->Get(1) == 4);
    assert(collection3->Get(2) == 5);
    assert(collection3->Get(3) == 6);

    Collection<int>* collection4 = collection1.GetSubsequence(0,1);

    assert(collection4->GetFirst() == 1);
    assert(collection4->GetLast() == 2);
    assert(collection4->Get(0) == 1);
    assert(collection4->Get(1) == 2);

    collection1.InsertAt(5000, 0);
    assert(collection1.GetFirst() == 5000);

    collection1.InsertAt(5000, 6);
    assert(collection1.Get(6) == 5000);

    assert(collection2.GetFirst() == 4);
    assert(collection2.GetLast() == 6);
    assert(collection2.Get(0) == 4);
    assert(collection2.Get(1) == 5);
    assert(collection2.Get(2) == 6);

    delete collection3;
    delete collection4;


    ArraySequence<int> arraySequence = ArraySequence<int>(&{2,3,4},3);

    MutableListSequence<int> listSequence = MutableListSequence<int>();


    return 1;
}

#endif //TESTING_H
