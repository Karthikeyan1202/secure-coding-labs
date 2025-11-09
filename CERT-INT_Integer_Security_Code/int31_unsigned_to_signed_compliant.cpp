#include <cstdio>
#include <climits>
void func() {
  unsigned long u = ULONG_MAX;
  if (u <= SCHAR_MAX)
    printf("Compliant: %d\n", (signed char)u);
  else
    puts("Error: exceeds signed char range");
}
int main(){func();}
