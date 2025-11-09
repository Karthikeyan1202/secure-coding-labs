#include <cstdio>
#define BUF 32
// noncompliant: gets() removed and unsafe (no bound checks)
int main() {
    char buf[BUF];
    // gets(buf); // intentionally not present (removed from modern runtimes)
    std::printf("Noncompliant example: gets() would be unsafe and is removed from C11.\n");
    return 0;
}
