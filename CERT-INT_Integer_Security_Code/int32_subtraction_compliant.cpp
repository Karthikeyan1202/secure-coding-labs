#include <cstdio>
#include <climits>
void func(int a,int b){
  if((b>0&&a<INT_MIN+b)||(b<0&&a>INT_MAX+b))
    puts("Overflow");
  else
    printf("Diff:%d\n",a-b);
}
int main(){func(-2147483648,1);func(100,50);}
