#include <cstdio>
int main() {
    // noncompliant: modifying a string literal -> undefined behavior
    char *s = (char*)"hello";
    s[0] = 'H'; // UB: likely crash or memory protection fault
    std::printf("%s\n", s);
    return 0;
}
