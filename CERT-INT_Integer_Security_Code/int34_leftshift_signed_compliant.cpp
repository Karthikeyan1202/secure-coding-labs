#include <cstdio>
#include <climits>
#define PRECISION(x) (sizeof(x)*CHAR_BIT)
void func(long a,long b){
  if(a<0||b<0||b>=PRECISION(ULONG_MAX)||(a>(LONG_MAX>>b)))
    puts("Invalid shift");
  else
    printf("Left shift:%ld\n",a<<b);
}
int main(){func(5,31);}
