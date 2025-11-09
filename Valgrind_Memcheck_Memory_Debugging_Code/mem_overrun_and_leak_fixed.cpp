#include <cstdlib>

void f(void)
{
    int* x = (int*)std::malloc(10 * sizeof(int));
    if (x == nullptr) return;
    // fix: use last valid index
    x[9] = 0;
    std::free(x);
}

int main(void)
{
    f();
    return 0;
}
