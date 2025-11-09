#include <stdio.h>
#include <limits.h>

void multiply(int si_a, int si_b) {
    if (si_a > 0 && si_b > INT_MAX / si_a) {
        printf("Error: Multiplication would overflow.\n");
        return;
    } else if (si_a < 0 && si_b < INT_MIN / si_a) {
        printf("Error: Multiplication would underflow.\n");
        return;
    }

    unsigned int product = si_a * si_b;
    printf("Product: %d\n", product);
}

int main() {
    multiply(4000000000 , 2); // Will handle overflow
    return 0;
}
