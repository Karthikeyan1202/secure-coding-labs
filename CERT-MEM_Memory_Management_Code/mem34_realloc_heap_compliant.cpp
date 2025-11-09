#include <cstdlib>
#include <cstdio>

enum { BUFSIZE = 256 };

void f(void) {
    char *buf = (char *)malloc(BUFSIZE * sizeof(char));
    if (buf == NULL) {
        std::printf("Error: malloc failed\n");
        return;
    }
    char *p = (char *)realloc(buf, 2 * BUFSIZE);
    if (p == NULL) {
        free(buf);
        std::printf("Error: realloc failed\n");
        return;
    }
    buf = p;
    free(buf);
}

int main() { f(); return EXIT_SUCCESS; }
