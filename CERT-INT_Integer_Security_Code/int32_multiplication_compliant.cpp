#include <cstdio>
#include <climits>
void func(int a,int b){
  if((a>0&&b>0&&a>INT_MAX/b)||
     (a>0&&b<0&&b<INT_MIN/a)||
     (a<0&&b>0&&a<INT_MIN/b)||
     (a<0&&b<0&&a!=0&&b<INT_MAX/a))
    puts("Overflow");
  else
    printf("Prod:%d\n",a*b);
}
int main(){func(2000000000,2);func(100,50);}
