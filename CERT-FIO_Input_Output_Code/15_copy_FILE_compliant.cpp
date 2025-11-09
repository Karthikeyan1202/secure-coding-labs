/* FIO38-C: Compliant - use pointer to FILE */
#include <cstdio>

int main(void) {
    FILE *my_stdout = stdout; /* use pointer, not copy */
    if (fputs("Hello, World!\n", my_stdout) == EOF) {
        printf("Error writing to stdout.\n");
    }
    return 0;
}
