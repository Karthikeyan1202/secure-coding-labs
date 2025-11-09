#include <stdio.h>
#include <limits.h>

void func(signed long s_a, signed long s_b) {
    signed long result;
    
    // Check for division by zero or overflow in signed long division
    if (s_b == 0 || (s_a == LONG_MIN && s_b == -1)) {
        printf("Error: Division by zero or overflow\n");
    } else {
        result = s_a % s_b;
        printf("Remainder: %ld\n", result);
    }
}

int main() {
    func(-2147483648 , -1); // Example that may cause overflow
    func(100 , 7); // Safe remainder
    return 0;
}
