#include <iostream>

int main()
{
    int *p = new int[10];
    p[9] = 1; // correct last element
    delete[] p; // free dynamically allocated memory
    return 0;
}
