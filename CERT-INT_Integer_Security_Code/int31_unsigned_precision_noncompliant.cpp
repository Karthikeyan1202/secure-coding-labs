#include <cstdio>
#include <climits>
void func(){
  unsigned long u = ULONG_MAX;
  unsigned char uc = (unsigned char)u;
  printf("Noncompliant: %u\n", uc);
}
int main(){func();}
