/* mylib.c
 * Toy shared library that overrides sleep() for demonstration with LD_PRELOAD.
 *
 * Correct POSIX signature: unsigned int sleep(unsigned int seconds)
 *
 * Build as shared object (non-setuid programs will honor LD_PRELOAD).
 */
#include <stdio.h>
#include <unistd.h>

unsigned int sleep(unsigned int seconds)
{
    (void)seconds;
    puts("LD_PRELOAD override: sleep() intercepted");
    return 0;
}
