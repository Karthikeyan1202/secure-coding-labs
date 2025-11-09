#include <iostream>
using namespace std;

int main()
{
    int x; // uninitialized
    cout << x << endl; // UB: reading uninitialized variable
    return 0;
}
