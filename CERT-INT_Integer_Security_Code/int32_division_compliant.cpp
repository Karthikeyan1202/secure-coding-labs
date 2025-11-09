#include <cstdio>
#include <climits>
void func(long a,long b){
  if(b==0||(a==LONG_MIN&&b==-1))
    puts("Error divide by zero/overflow");
  else
    printf("Result:%ld\n",a/b);
}
int main(){func(-2147483648,-1);func(100,5);}
