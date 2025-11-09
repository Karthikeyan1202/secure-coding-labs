#include <stdio.h>
#include <limits.h>

void func(signed long s_a) {
    signed long result;

    // Check for unary negation overflow for signed long
    if (s_a == LONG_MIN) {
        printf("Error: Unary negation overflow\n");
    } else {
        result = -s_a;
        printf("Negated Result: %ld\n", result);
    }
}

int main() {
    func(-2147483648); // Example that may cause overflow
    func(100); // Safe negation
    return 0;
}
