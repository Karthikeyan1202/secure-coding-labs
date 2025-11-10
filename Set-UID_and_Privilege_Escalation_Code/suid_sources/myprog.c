/* myprog.c
 * Calls sleep(1). Useful to test LD_PRELOAD with the mylib shared object.
 */
#include <unistd.h>

int main(void)
{
    sleep(1);
    return 0;
}
