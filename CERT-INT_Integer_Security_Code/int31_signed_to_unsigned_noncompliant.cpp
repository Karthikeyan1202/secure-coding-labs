#include <cstdio>
#include <climits>
void func(int si){
  unsigned int ui = (unsigned int)si;
  printf("Noncompliant: %u\n", ui);
}
int main(){ func(INT_MIN); }
