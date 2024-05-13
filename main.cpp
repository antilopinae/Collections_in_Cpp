#include <iostream>
#include "ListSequence.h"
#include "ArraySequence.h"
#include "Testing.h"


int main() {
    if(test()) std::cout<<"TESTS SUCCESS"<<std::endl;
    else throw "TESTS FAILED";



    return 0;
}