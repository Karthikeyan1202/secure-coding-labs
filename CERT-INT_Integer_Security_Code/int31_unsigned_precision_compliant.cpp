#include <cstdio>
#include <climits>
void func(){
  unsigned long u = ULONG_MAX;
  if (u > UCHAR_MAX) puts("Error: exceeds range");
  else printf("Compliant: %u\n", (unsigned char)u);
}
int main(){func();}
