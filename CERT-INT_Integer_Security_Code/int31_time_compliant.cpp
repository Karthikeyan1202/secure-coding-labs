#include <cstdio>
#include <ctime>
void func(){
  time_t now = time(NULL);
  if (now != (time_t)-1)
    printf("Compliant: time=%ld\n", (long)now);
  else
    puts("Error: time unavailable");
}
int main(){func();}
