#include <cstdlib>
#include <cstdio>

enum { BUFSIZE = 256 };

void f(void) {
    char buf[BUFSIZE];
    char *p = (char *)realloc(buf, 2 * BUFSIZE); /* ERROR: buf not heap memory */
    if (p == NULL) {
        std::printf("Error\n");
        return;
    }
    free(p);
}

int main() { f(); return EXIT_SUCCESS; }
