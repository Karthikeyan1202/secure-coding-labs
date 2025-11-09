#include <cstdlib>
#include <cstdio>
#include <cstring>

enum { MAX_ALLOCATION = 1000 };

int main(int argc, const char *argv[]) {
    char *c_str = NULL;
    if (argc == 2) {
        size_t len = std::strlen(argv[1]) + 1;
        if (len > MAX_ALLOCATION) return EXIT_FAILURE;
        c_str = (char *)malloc(len);
        if (c_str == NULL) return EXIT_FAILURE;
        std::strcpy(c_str, argv[1]);
        std::printf("Copied string: %s\n", c_str);
        free(c_str);
    } else {
        std::printf("%s\n", "usage: $>a.exe [string]");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
