#include <cstdio>
#include <cstdlib>
void func(size_t n, size_t s) {
  size_t total = n * s;
  printf("Multiplying %zu * %zu = %zu\n", n, s, total);
  void* p = malloc(total);
  if (p) { puts("Allocation ok"); free(p); }
  else puts("Allocation failed");
}
int main() { func(1000000000, 8); return 0; }
