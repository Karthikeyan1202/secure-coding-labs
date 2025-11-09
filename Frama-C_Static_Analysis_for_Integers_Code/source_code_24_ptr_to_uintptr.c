#include <stdint.h>
#include <stdio.h>

void f(void) {
    const char *ptr = "Hello , World!"; // Use const char* for string literals
    
    uintptr_t number = (uintptr_t)ptr; // Use uintptr_t for pointer to integer conversion
    printf("Number: %lu\n", (unsigned long)number); // Print as unsigned long
}

int main() {
    f();
    return 0;
}
