#include <cstdlib>
#include <cstdio>
#include <stdint.h>

void function(size_t len) {
    long *p;
    if (len == 0 || len > SIZE_MAX / sizeof(long)) {
        std::printf("Error\n");
        return;
    }
    p = (long *)malloc(len * sizeof(int)); /* BUG: used sizeof(int) instead of sizeof(long) */
    if (p == NULL) return;
    free(p);
}

int main(){ function(10); return EXIT_SUCCESS; }
