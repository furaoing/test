#include <iostream>

using namespace std;

template <typename T>
T test (T a)
{
    if(T==int)
    return 2*a;
}

int main() {
    enum my_e {time = 11,};

    cout << "Result is:" << test<double>(1) << endl;
    return 0;
}