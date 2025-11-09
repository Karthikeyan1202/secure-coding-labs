#include <stdio.h>
#include <limits.h>

void func(int si_a, int si_b) {
    int sdiff;

    if (si_a < si_b) {
        printf("Error: Subtraction would underflow.\n");
        return;
    } else {
        sdiff = si_a - si_b;
    }
    printf("Difference: %d\n", sdiff);
}

int main() {
    func(10, 20); // Handles error
    return 0;
}
