/* copy_strncpy.c
 * Safe copy using strncpy with explicit NUL termination
 */
#include <stdio.h>
#include <string.h>

void copy_in(const char *src) {
    char name[10];
    /* copy at most sizeof(name)-1 and ensure termination */
    strncpy(name, src, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
    printf("Copied name: %s\n", name);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        copy_in(argv[1]);
    } else {
        printf("No argument provided\n");
    }
    return 0;
}
