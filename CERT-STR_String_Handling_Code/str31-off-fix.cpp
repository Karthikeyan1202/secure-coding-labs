#include <cstdio>
#include <cstring>
void copy_fix(const char *src, char *dst, size_t n) {
    size_t i;
    if (n == 0) return;
    // compliant: leave room for terminating NUL
    for (i = 0; src[i] && (i < n - 1); ++i) {
        dst[i] = src[i];
    }
    dst[i] = '\\0';
}
int main() {
    const char src[] = "Hello, world!";
    char dst[12];
    copy_fix(src, dst, sizeof(dst));
    std::printf("dst = %s\n", dst);
    return 0;
}
