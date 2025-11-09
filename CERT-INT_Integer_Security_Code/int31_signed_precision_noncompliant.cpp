#include <cstdio>
#include <climits>
void func(){
  long s = LONG_MAX;
  signed char sc = (signed char)s;
  printf("Noncompliant: %d\n", sc);
}
int main(){func();}
