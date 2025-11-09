/* FIO37-C: Noncompliant - assumes fgets returned non-empty string and manipulates strlen(buf)-1 */
#include <cstdio>
#include <cstring>

enum { BUFFER_SIZE = 1024 };

void func(void) {
    char buf[BUFFER_SIZE];
    /* Simulated input */
    const char *input = "Hello , World!\n";
    std::strncpy(buf, input, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    if (buf[0] == '\0') {
        printf("Error: No input received.\n");
        return;
    }
    /* Unsafe: if buf[0] == '\\0' this underflows */
    buf[strlen(buf) - 1] = '\0';
}

int main() { func(); return 0; }
