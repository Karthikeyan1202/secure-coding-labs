#include <cstdio>
#include <ctime>
void func(){
  time_t now = time(NULL);
  if (now != -1)
    printf("Noncompliant: time=%ld\n", (long)now);
  else
    puts("time unavailable");
}
int main(){func();}
