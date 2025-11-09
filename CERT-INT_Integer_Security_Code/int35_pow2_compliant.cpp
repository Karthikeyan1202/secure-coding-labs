#include <cstdio>
#include <climits>
#include <cstdint>
size_t popcount(uintmax_t n){size_t c=0;while(n){c+=n&1;n>>=1;}return c;}
#define PRECISION(x) popcount(x)
unsigned int pow2(unsigned int e){
  if(e>=PRECISION(UINT_MAX)){
    puts("Exponent out of range");
    return 0;
  }
  return 1U<<e;
}
int main(){printf("Result:%u\n",pow2(31));}
