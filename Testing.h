//
// Created by antilopa on 13.05.24.
//

#ifndef TESTING_H
#define TESTING_H

#include <assert.h>
#include "LinkedList.h"
#include "ListSequence.h"
#include "ArraySequence.h"
#include "MutableStack.h"

int test() {
    {
        LinkedList<int> collection1 = LinkedList<int>();

        collection1.Append(3);
        collection1.Prepend(2);
        collection1.InsertAt(1, 0);

        assert(collection1.GetFirst() == 1);
        assert(collection1.GetLast() == 3);
        assert(collection1.Get(0) == 1);
        assert(collection1.Get(1) == 2);
        assert(collection1.Get(2) == 3);

        LinkedList<int> collection2 = LinkedList<int>();

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

        LinkedList<int>* collection3 = collection1.GetSubsequence(2,5);

        assert(collection3->Get(0) == 3);
        assert(collection3->Get(1) == 4);
        assert(collection3->Get(2) == 5);
        assert(collection3->Get(3) == 6);

        LinkedList<int>* collection4 = collection1.GetSubsequence(0,1);

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
    }

    {
        int nums[4] = {1,2,3,4};
        ArraySequence<int> arraySequence1 = ArraySequence<int>(nums,4);

        assert(arraySequence1.GetFirst() == 1);
        assert(arraySequence1.GetLast() == 4);
        assert(arraySequence1.Get(0) == 1);
        assert(arraySequence1.Get(1) == 2);
        assert(arraySequence1.Get(2) == 3);
        assert(arraySequence1.Get(3) == 4);

        int nums2[1] = {1};
        ArraySequence<int> arraySequence2 = ArraySequence<int>(nums, 1);

        assert(arraySequence2.GetFirst() == 1);
        assert(arraySequence2.GetLast() == 1);
        assert(arraySequence2.Get(0) == 1);
    }

    {
        ListSequence<int> listSequence1 = ListSequence<int>();
        listSequence1.Append(3);
        listSequence1.Prepend(2);
        listSequence1.InsertAt(1, 0);

        assert(listSequence1.GetFirst() == 1);
        assert(listSequence1.GetLast() == 3);
        assert(listSequence1.Get(0) == 1);
        assert(listSequence1.Get(1) == 2);
        assert(listSequence1.Get(2) == 3);

        ListSequence<int> listSequence2 = ListSequence<int>();

        listSequence2.Append(6);
        listSequence2.Prepend(4);
        listSequence2.InsertAt(5, 1);

        assert(listSequence2.GetFirst() == 4);
        assert(listSequence2.GetLast() == 6);
        assert(listSequence2.Get(0) == 4);
        assert(listSequence2.Get(1) == 5);
        assert(listSequence2.Get(2) == 6);

        listSequence2.Delete(2);
        assert(listSequence2.Get(0) == 4);
        assert(listSequence2.Get(1) == 5);

        listSequence2.Delete(0);
        listSequence2.Delete(0);

        assert(listSequence2.GetLength() == 0);

        listSequence2.DeleteCollection();

        listSequence2.Append(10);
        listSequence2.Append(11);
        listSequence2.Append(12);
        listSequence2.Prepend(9);

        assert(listSequence2.Get(0) == 9);
        assert(listSequence2.Get(1) == 10);
        assert(listSequence2.Get(2) == 11);
        assert(listSequence2.Get(3) == 12);

        listSequence2.Delete(2);

        assert(listSequence2.Get(0) == 9);
        assert(listSequence2.Get(1) == 10);
        assert(listSequence2.Get(2) == 12);

        listSequence2.InsertAt(11,2);

        assert(listSequence2.Get(0) == 9);
        assert(listSequence2.Get(1) == 10);
        assert(listSequence2.Get(2) == 11);
        assert(listSequence2.Get(3) == 12);

        listSequence2.InsertAt(8, 0);

        assert(listSequence2.GetLength() == 5);

        assert(listSequence2.Get(0) == 8);
        assert(listSequence2.Get(1) == 9);
        assert(listSequence2.Get(2) == 10);
        assert(listSequence2.Get(3) == 11);
        assert(listSequence2.Get(4) == 12);

        listSequence2.DeleteCollection();

        assert(listSequence2.GetLength() == 0);
    }

//    {
//        MutableStack<int> mutableStack1 = MutableStack<int>();
//
//        for(int i = 0; i<20; ++i){
//            mutableStack1.Append(i*i*i);
//        }
//
//        for(int i = 19; i>=0; --i){
//            int element = mutableStack1.GetLast();
//            assert(element == i*i*i);
//        }
//
//        assert(mutableStack1.GetLength() == 0);
//
//        for(int i = 0; i<20; ++i){
//            mutableStack1.Append(i*i);
//        }
//
//        MutableStack<int>* mutableStack2 = new MutableStack<int>();
//
//        for(int i = 0; i<20; ++i){
//            mutableStack2->Append(i);
//        }
//
//        assert(mutableStack2->GetLength() == 20);
//
//        mutableStack1.Concat(mutableStack2);
//
//        for(int i = 19; i>=0; --i){
//            assert(mutableStack1.GetLast()==i);
//        }
//        for(int i = 19; i>=0; --i){
//            assert(mutableStack1.GetLast()== i*i);
//        }
//
//        assert(mutableStack1.GetLength() == 0);
//
//        for(int i = 19; i>=0; --i){
//            assert(mutableStack2->GetLast() == i);
//        }
//
//        assert(mutableStack2->GetLength() == 0);
//
//        for(int i = 0; i<20; ++i){
//            mutableStack2->Append(i);
//        }
//
//        MutableStack<int>* mutableStack3;
//        mutableStack3 = mutableStack2->GetSubsequence(1,19);
//
//        for(int i = 19; i>=1; --i){
//            assert(mutableStack3->GetLast()==i);
//        }
//        assert(mutableStack3->GetLength() == 0);
//
//        mutableStack3->DeleteCollection();
//        mutableStack2->DeleteCollection();
//        mutableStack1.DeleteCollection();
//
//        delete mutableStack2;
//        delete mutableStack3;
//    }

    return 1;
}

#endif //TESTING_H
