/*
 * Off-by-one / buffer-size mistake (vulnerable).
 * The loop condition can write past the end of allocated memory.
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>

int main(void) {
    char s1[] = "012345678";       /* 9 chars + '\0' -> size 10 */
    char s2[] = "0123456789";      /* 10 chars + '\0' -> size 11 */
    char *dest;
    int i;

    /* Incorrect: dest allocated without space for null terminator and loop goes out of bounds */
    dest = (char *)malloc(strlen(s1)); /* missing +1 */
    if (!dest) return 1;

    for (i = 0; i <= 11; i++) {       /* Vulnerable: i <= 11 writes beyond buffers */
        dest[i] = s1[i];
    }
    dest[i] = '\0';
    std::printf("dest = %s\n", dest);

    free(dest);
    return 0;
}
