#include <cstdio>
void func(unsigned int flag){
  char* p="Hello"; unsigned int n=(unsigned int)p;
  n=(n&0x7fffff)|(flag<<23); p=(char*)n;
  printf("%s",p);
}
int main(){func(1);}
