#include <cstdio>
#include <climits>
void func(int a,int b){
  if((b>0&&a>INT_MAX-b)||(b<0&&a<INT_MIN-b))
    puts("Overflow");
  else
    printf("Sum:%d\n",a+b);
}
int main(){func(2147483647,1);func(100,50);}
