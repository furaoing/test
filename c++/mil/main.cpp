#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

int main() {
    int buff_size = 1024;
    char a[buff_size];
    a[0] = 'y';
    a[1] = 'c';
    //memset(&a+1, 0, buff_size-1);
    //string my_str("afdfsdf");

    //my_str.copy(a, buff_size, 0);
    // a[0] = 'y';
    int b = 1;
    int c = b;
    if (a[0]==0) {
        cout << "Address of b is:" << a[0] << "###" << endl;
    }
    cout << "Address of array a (&a) is:" << "fdsff" << endl;
    sleep(5);
    cout << "Address of array a (a+1) is:" << "afdf" << endl;

/*
    cout << "Content of a is: " << a << "##" << endl;
    */
    cout << "Hello, World!" << endl;
    return 0;
}