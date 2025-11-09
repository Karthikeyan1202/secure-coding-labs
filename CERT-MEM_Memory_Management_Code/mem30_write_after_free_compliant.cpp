#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char *argv[]) {
    if (argc == 0) return 0;
    const size_t bufsize = std::strlen(argv[0]) + 1;
    char *buf = (char *)malloc(bufsize);
    if (!buf) {
        std::perror("malloc failed");
        return EXIT_FAILURE;
    }
    std::strcpy(buf, argv[0]);
    std::printf("Program name: %s\n", buf);
    /* Final use before free */
    free(buf);
    return EXIT_SUCCESS;
}
