#include <cstdio>
#include <climits>
void func(long a){
  if(a==LONG_MIN)puts("Negation overflow");
  else printf("Neg:%ld\n",-a);
}
int main(){func(-2147483648);func(100);}
