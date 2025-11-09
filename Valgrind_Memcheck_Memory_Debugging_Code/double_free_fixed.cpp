#include <cstdlib>
#include <cstdio>

int main ()
{
    int n = 10;
    int *x = (int*)std::malloc(n * sizeof(int));
    if (x == nullptr) { std::perror("malloc for x failed"); return 1; }

    for (int i = 0; i < n; i++) { x[i] = i; std::printf("x[%d] = %d\n", i, x[i]); }
    std::free(x);

    int *y = (int*)std::malloc(n * sizeof(int));
    if (y == nullptr) { std::perror("malloc for y failed"); return 1; }

    for (int i = 0; i < n; i++) { y[i] = i * 2; std::printf("y[%d] = %d\n", i, y[i]); }
    std::free(y);
    return 0;
}
