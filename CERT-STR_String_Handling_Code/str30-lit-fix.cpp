#include <cstdio>
#include <cstring>
int main() {
    // compliant: make modifiable copy
    const char *lit = "hello";
    char s[6];
    std::strncpy(s, lit, sizeof(s));
    s[sizeof(s)-1] = '\\0';
    s[0] = 'H';
    std::printf("%s\n", s);
    return 0;
}
