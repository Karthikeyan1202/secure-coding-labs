#include <string.h>
#include <stdio.h>

signed int *init_memory(signed int *array , size_t n) {
    return memset(array , 0, n); // Safe to set to zero
}

int  main(void)  {
    signed int array[10]; // Explicitly using signed int

    init_memory(array , sizeof(array));

    printf("First element (initialized to zero): %d\n", array[0]); // Should print 0
    return 0;
}
