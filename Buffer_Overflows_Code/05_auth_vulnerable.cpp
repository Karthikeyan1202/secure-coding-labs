/*
 * Authentication example vulnerable to buffer overflow because of strcpy.
 * Using argv[] directly into fixed-size buffers without checks is unsafe.
 */
#include <cstdio>
#include <cstring>

int main(int argc, char** argv) {
    int authentication = 0;
    char cUsername[10], cPassword[10];

    if (argc < 3) {
        std::printf("Usage: %s <username> <password>\n", argv[0]);
        return 1;
    }

    /* Vulnerable: no bounds checking */
    std::strcpy(cUsername, argv[1]);
    std::strcpy(cPassword, argv[2]);

    if (std::strcmp(cUsername, "admin") == 0 && std::strcmp(cPassword, "adminpass") == 0) {
        authentication = 1;
    }

    if (authentication) {
        std::printf("Access Granted\n");
    } else {
        std::printf("Wrong Username and Password\n");
    }

    return 0;
}
