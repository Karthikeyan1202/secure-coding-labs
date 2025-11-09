#include <cstdio>
#include <cstring>
#define BUF 32
int main() {
    char buf[BUF];
    std::printf("Enter a string: ");
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        std::perror("fgets");
        return 1;
    }
    // remove trailing newline if present
    char *p = std::strchr(buf, '\\n');
    if (p) *p = '\\0';
    std::printf("You entered: %s\n", buf);
    return 0;
}
