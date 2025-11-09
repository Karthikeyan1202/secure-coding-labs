/* FIO30-C: Compliant solution using fprintf() with explicit format */
#include <cstdio>

void incorrect_password_compliant(const char *user) {
    static const char msg_format[] = "%s cannot be authenticated.\n";
    std::fprintf(stderr, msg_format, user);
}

int main() {
    const char *username = "example_user";
    incorrect_password_compliant(username);
    return 0;
}
