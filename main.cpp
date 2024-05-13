#include "Testing.h"
#include "Debugging.h"


int main() {
    if(test()) std::cout<<"TESTS SUCCESS"<<std::endl;
    else throw "TESTS FAILED";

    View view = View();
    view.StartView();

    return 0;
}