/* heap_demo.c
 * Demonstrates heap allocation vs stack variable addresses
 */
#include <stdio.h>
#include <stdlib.h>

int func(void) {
    int a = 10;
    int *aptr = &a;
    int *ptr = (int *)malloc(sizeof(int));
    if (!ptr) return -1;
    *ptr = 20;
    printf("Heap value = %d\n", *ptr);
    printf("Stack value (via pointer) = %d\n", *aptr);
    free(ptr);
    return 0;
}

int main(void) {
    func();
    return 0;
}
