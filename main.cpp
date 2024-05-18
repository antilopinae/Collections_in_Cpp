#include "Testing.h"
#include "Debugging.h"


int main() {
    if(test()) std::cout<<"TESTS SUCCESS\n"<<std::endl;
    else throw "TESTS FAILED";

    debug();

    return 0;
}