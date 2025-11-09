#include <cstdio>
#include <cstring>
void copy_bad(const char *src, char *dst, size_t n) {
    size_t i;
    // noncompliant: loop may write terminating NUL out of bounds
    for (i = 0; src[i] && (i < n); ++i) {
        dst[i] = src[i];
    }
    dst[i] = '\\0'; // if i == n this writes past dst[n-1]
}
int main() {
    const char src[] = "Hello, world!";
    char dst[12];
    copy_bad(src, dst, sizeof(dst));
    std::printf("dst = %s\n", dst);
    return 0;
}
