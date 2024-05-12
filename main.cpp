#include <iostream>
#include "ListSequence.h"
#include "ArraySequence.h"
#include "Collection.h"

int main() {
    //smth here
    Collection<int> collection = Collection<int>();
    collection.Append(17);
    collection.Append(20);
    collection.Append(40);
    std::cout<<collection.GetLength()<< std::endl;
    return 0;
}


//
//    Ebook cppbook {"About C++", 320, 5.6};
//    static_cast<Book&>(cppbook).print();    // 320 pages
//