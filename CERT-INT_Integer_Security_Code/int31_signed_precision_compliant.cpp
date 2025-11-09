#include <cstdio>
#include <climits>
void func(){
  long s = LONG_MAX;
  if (s < SCHAR_MIN || s > SCHAR_MAX)
    puts("Error: exceeds range");
  else
    printf("Compliant: %d\n", (signed char)s);
}
int main(){func();}
