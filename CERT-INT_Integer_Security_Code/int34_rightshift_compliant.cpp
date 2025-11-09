#include <cstdio>
#include <climits>
#define PRECISION(x) (sizeof(x)*CHAR_BIT)
void func(unsigned int a,unsigned int b){
  if(b>=PRECISION(UINT_MAX))
    puts("Shift exceeds precision");
  else
    printf("Right shift:%u\n",a>>b);
}
int main(){func(10,2);}
