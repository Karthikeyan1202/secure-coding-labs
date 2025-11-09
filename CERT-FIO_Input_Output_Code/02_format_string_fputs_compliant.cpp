/* FIO30-C: Compliant solution using fputs() */
#include <cstdio>
#include <cstdlib>
#include <cstring>

void incorrect_password_fputs(const char *user) {
    int ret;
    static const char msg_format[] = "%s cannot be authenticated.\n";
    size_t len = strlen(user) + sizeof(msg_format);
    char *msg = (char *)malloc(len);
    if (msg == NULL) {
        std::fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    ret = std::snprintf(msg, len, msg_format, user);
    if (ret < 0) {
        std::fprintf(stderr, "Error formatting message.\n");
        free(msg);
        return;
    } else if ((size_t)ret >= len) {
        std::fprintf(stderr, "Truncated output.\n");
        free(msg);
        return;
    }
    /* Safe: do not treat msg as format string */
    std::fputs(msg, stderr);
    free(msg);
}

int main() {
    const char *username = "user1";
    incorrect_password_fputs(username);
    return 0;
}
