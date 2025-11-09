#include <cstdio>
struct PtrFlag{char* pointer; unsigned int flag:9;};
void func(unsigned int flag){
  PtrFlag pf; pf.pointer="Hello"; pf.flag=flag;
  printf("%s %u\\n",pf.pointer,pf.flag);
}
int main(){func(1);}
