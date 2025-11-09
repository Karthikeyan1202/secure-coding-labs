/*
 * Fixed authentication using argc checks, strncpy and explicit null termination.
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

    /* Safely copy with size limit and guarantee null-termination */
    std::strncpy(cUsername, argv[1], sizeof(cUsername) - 1);
    cUsername[sizeof(cUsername) - 1] = '\0';

    std::strncpy(cPassword, argv[2], sizeof(cPassword) - 1);
    cPassword[sizeof(cPassword) - 1] = '\0';

    /* Compare safely */
    if (std::strcmp(cUsername, "admin") == 0 && std::strcmp(cPassword, "adminpass") == 0) {
        authentication = 1;
    }

    if (authentication) {
        std::printf("Access Granted\n");
    } else {
        std::printf("Wrong Username or Password\n");
    }

    return 0;
}
