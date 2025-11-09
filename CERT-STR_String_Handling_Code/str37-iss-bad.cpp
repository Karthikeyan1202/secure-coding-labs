#include <cstdio>
#include <cctype>
#include <cstring>
size_t count_ws_bad(const char *s) {
    const char *t = s;
    while (*t && std::isspace(*t)) ++t; // noncompliant: *t may be negative -> undefined
    return (size_t)(t - s);
}
int main() {
    const char s[] = "  lead";
    std::printf("ws: %zu\n", count_ws_bad(s));
    return 0;
}
