#include <stdint.h>
#include <stdio.h>

void f(void) {
    char *ptr = "Hello , World!";
    intptr_t number = (intptr_t)ptr; // Cast to signed integer type
    
    printf("Number: %ld\n", (long)number); // Print as signed long
}

int main() {
    f();
    return 0;
}
