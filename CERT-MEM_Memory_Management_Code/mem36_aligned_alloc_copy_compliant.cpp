#include <cstdlib>
#include <cstring>
#include <cstdio>

void func(void) {
    size_t resize = 1024;
    size_t alignment = 1 << 12;
    int *ptr;
    int *ptr1;

    ptr = (int *)aligned_alloc(alignment, sizeof(int));
    if (ptr == NULL) { std::printf("alloc failed\n"); return; }

    ptr1 = (int *)aligned_alloc(alignment, resize);
    if (ptr1 == NULL) { free(ptr); std::printf("alloc failed\n"); return; }

    if (memcpy(ptr1, ptr, sizeof(int)) == NULL) { free(ptr); free(ptr1); return; }

    free(ptr);
    free(ptr1);
}

int main() { func(); std::printf("Aligned alloc/copy done\n"); return 0; }
