/* FIO37-C: Compliant - use strchr to find newline and replace safely */
#include <cstdio>
#include <cstring>

enum { BUFFER_SIZE = 1024 };

void func(void) {
    char buf[BUFFER_SIZE];
    char *p;
    const char *input = "Hello , World!\n";
    std::strncpy(buf, input, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    if (buf[0] == '\0') {
        printf("Error: No input received.\n");
        return;
    }
    p = std::strchr(buf, '\n');
    if (p) *p = '\0';
    printf("Processed input: %s\n", buf);
}

int main() { func(); return 0; }
