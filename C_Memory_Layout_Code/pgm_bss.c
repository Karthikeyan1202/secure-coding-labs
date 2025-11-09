/* pgm_bss.c
 * Uninitialized (BSS) segment example
 */
#include <stdio.h>

int a, b, c;
char ch;

int main(void) {
    printf("a=%d b=%d c=%d ch=%d\n", a, b, c, (int)ch);
    return 0;
}
