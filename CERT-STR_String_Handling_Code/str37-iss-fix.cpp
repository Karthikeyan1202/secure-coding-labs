#include <cstdio>
#include <cctype>
#include <cstring>
size_t count_ws_fix(const char *s) {
    const unsigned char *t = (const unsigned char *)s;
    while (*t && std::isspace((int)*t)) ++t; // compliant: cast to unsigned char first
    return (size_t)(t - (const unsigned char *)s);
}
int main() {
    const char s[] = "  lead";
    std::printf("ws: %zu\n", count_ws_fix(s));
    return 0;
}
