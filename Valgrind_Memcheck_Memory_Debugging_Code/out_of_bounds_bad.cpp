#include <iostream>

int main()
{
    int *p = new int[10];
    // BUG: accessing index 10 is out-of-bounds (valid 0..9)
    p[10] = 1;
    // missing delete[] -> memory leak
    return 0;
}
