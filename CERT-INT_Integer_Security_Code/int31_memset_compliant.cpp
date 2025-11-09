#include <cstdio>
#include <cstring>
int* init_memory(int* a, size_t n){ return (int*)memset(a,0,n); }
int main(){ int arr[10]; init_memory(arr,sizeof(arr)); puts("Compliant memset zero"); }
