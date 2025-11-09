#include <cstdio>
#include <climits>
void func(long a,long b){
  if(a<0||b<0||b>=sizeof(long)*8||a>(LONG_MAX>>b))
    puts("Shift overflow");
  else
    printf("Shift:%ld\n",a<<b);
}
int main(){func(1,33);func(4,2);}
