#include <cstdio>
#include <climits>
void func() {
  unsigned long u = ULONG_MAX;
  signed char sc = (signed char)u;
  printf("Noncompliant: %d\n", sc);
}
int main(){func();}
