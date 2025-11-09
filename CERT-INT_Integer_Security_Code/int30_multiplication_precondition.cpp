#include <cstdio>
#include <cstdlib>
#include <climits>
void func(size_t n, size_t s) {
  if (n > SIZE_MAX / s)
    printf("Error: Multiplication would overflow\n");
  else {
    size_t total = n * s;
    printf("Allocating %zu bytes\n", total);
    void* p = malloc(total);
    if (p) { puts("Allocation ok"); free(p); }
    else puts("Allocation failed");
  }
}
int main() { func(1000000000, 8); return 0; }
