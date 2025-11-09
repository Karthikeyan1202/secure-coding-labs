#include <cstdlib>

void f(void)
{
    int* x = (int*)std::malloc(10 * sizeof(int));
    // BUG: write one past end -> heap block overrun
    x[10] = 0;
    // BUG: memory not freed -> leak
}

int main(void)
{
    f();
    return 0;
}
