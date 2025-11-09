/*
 * Vulnerable example: strcpy/strcat into a fixed buffer without bounds checks.
 * If argv[1] + " = " + argv[2] is larger than 2048, buffer overflow occurs.
 */
#include <cstdio>
#include <cstring>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::printf("Usage: %s <left> <right>\n", argv[0]);
        return 1;
    }
    char name[2048];
    /* Vulnerable: no size checks */
    std::strcpy(name, argv[1]);
    std::strcat(name, " = ");
    std::strcat(name, argv[2]);
    std::printf("%s\n", name);
    return 0;
}
