#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class my_class {

public:
    static const int attr = 1;
    int b;
    my_class (int a){
        // constructors has no return value;
        b = a;
    }
};


int main() {

    //my_class instance = my_class(33);

    cout << my_class::attr << endl;


/*
    cout << "Content of a is: " << a << "##" << endl;
    */
    cout << "Hello, World!" << endl;
    return 0;
}