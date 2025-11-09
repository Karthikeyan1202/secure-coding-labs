#include <cstdio>
#include <climits>
unsigned int pow2(unsigned int e){
  if(e>=sizeof(unsigned int)*CHAR_BIT){
    puts("Exponent out of range");
    return 0;
  }
  return 1U<<e;
}
int main(){printf("Result:%u\n",pow2(32));}
