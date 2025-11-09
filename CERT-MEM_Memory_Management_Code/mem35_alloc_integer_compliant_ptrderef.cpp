#include <cstdlib>
#include <cstdio>

void function(size_t len) {
    long *p;
    if (len == 0 || len > SIZE_MAX / sizeof(*p)) {
        std::printf("Error\n");
        return;
    }
    p = (long *)malloc(len * sizeof(*p)); /* sizeof(*p) is safe and maintainable */
    if (p == NULL) return;
    free(p);
}

int main(){ function(10); return EXIT_SUCCESS; }
