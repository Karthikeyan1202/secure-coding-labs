/*
 * Fixed off-by-one: proper sizes, strncpy, and safe copying.
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>

int main(void) {
    /* Make s1 large enough to hold 10 chars + null */
    char s1[11];
    char s2[] = "0123456789"; /* 10 characters */
    char *dest;
    int i;

    /* Safely copy s2 into s1 leaving space for NUL */
    std::strncpy(s1, s2, sizeof(s1) - 1);
    s1[sizeof(s1) - 1] = '\0';

    /* Allocate exact size +1 for null terminator */
    dest = (char *)malloc(strlen(s1) + 1);
    if (dest == NULL) {
        std::fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    /* Copy safely using length-based loop */
    for (i = 0; i < (int)strlen(s1); i++) {
        dest[i] = s1[i];
    }
    dest[i] = '\0';

    std::printf("dest = %s\n", dest);

    free(dest);
    return 0;
}
