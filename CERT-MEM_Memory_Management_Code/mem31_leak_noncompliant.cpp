#include <cstdio>
#include <cstdlib>

enum { BUFFER_SIZE = 32 };

int f(void) {
    char *text_buffer = (char *)malloc(BUFFER_SIZE);
    if (text_buffer == NULL) {
        return -1;
    }
    /* missing free -> memory leak */
    return 0;
}

int main() {
    if (f() == -1) {
        std::printf("Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    std::printf("Memory allocated successfully\n");
    return EXIT_SUCCESS;
}
