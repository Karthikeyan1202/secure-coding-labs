#include <cstdio>
unsigned int* g(){ return (unsigned int*)0xdeadbeef; }
int main(){ printf("%p\\n",(void*)g()); }
