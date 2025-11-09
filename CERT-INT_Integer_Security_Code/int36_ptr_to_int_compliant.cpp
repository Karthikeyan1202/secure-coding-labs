#include <cstdio>
#include <cstdint>
void f(){ char* p="Hello"; uintptr_t n=(uintptr_t)p; printf("%lu\n",(unsigned long)n); }
int main(){f();}
