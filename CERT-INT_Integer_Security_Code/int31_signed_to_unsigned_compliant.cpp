#include <cstdio>
#include <climits>
void func(int si){
  if (si < 0)
    puts("Error: negative cannot convert");
  else
    printf("Compliant: %u\n", (unsigned int)si);
}
int main(){ func(INT_MIN+1); }
