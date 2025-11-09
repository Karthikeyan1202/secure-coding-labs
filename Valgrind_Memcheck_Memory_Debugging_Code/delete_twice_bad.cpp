#include <iostream>

int main()
{
    int *p = new int(10);
    delete p;
    // BUG: double delete -> undefined behaviour
    delete p;
    return 0;
}
