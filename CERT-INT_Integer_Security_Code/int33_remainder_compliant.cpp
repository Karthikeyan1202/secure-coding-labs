#include <cstdio>
#include <climits>
void func(long a,long b){
  if(b==0||(a==LONG_MIN&&b==-1))
    puts("Error div0/overflow");
  else
    printf("Rem:%ld\n",a%b);
}
int main(){func(LONG_MIN,-1);func(10,3);}
