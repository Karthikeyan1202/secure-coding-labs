#include <iostream>

int main()
{
    int *p = new int(10);
    delete p;
    // Fixed: do not delete twice. Optionally null the pointer.
    p = nullptr;
    // delete p; // safe only if p != nullptr; but best to avoid double delete
    return 0;
}
