/* posix_memalign then realloc: alignment could be lost after realloc */
#include <cstdlib>
#include <cstdio>

int main(void) {
    size_t size = 16;
    size_t resize = 1024;
    size_t align = 1 << 12;
    int *ptr;
    int *ptr1;
    if (posix_memalign((void **)&ptr, align, size) != 0) exit(EXIT_FAILURE);
    std::printf("memory aligned to %zu bytes\n", align);
    std::printf("ptr = %p\n\n", (void*)ptr);
    ptr1 = (int*)realloc((int*)ptr, resize);
    if (ptr1 == NULL) exit(EXIT_FAILURE);
    std::printf("ptr1 = %p\n", (void*)ptr1);
    free(ptr1);
    return 0;
}
