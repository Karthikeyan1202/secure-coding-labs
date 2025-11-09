/* FIO30-C: Example (noncompliant) - constructing a message and passing it to fprintf as a format string */
#include <cstdio>
#include <cstdlib>
#include <cstring>

void incorrect_password_noncompliant(const char *user) {
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
    /* Vulnerability: msg may contain user-controlled '%' sequences */
    std::fprintf(stderr, msg);
    free(msg);
}

int main() {
    const char *username = "user1";
    incorrect_password_noncompliant(username);
    return 0;
}
