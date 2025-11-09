#include <stdio.h>
#include <limits.h>

void func(int si_a, int si_b) {
    int isum;

    if ((si_a > 0 && si_b > INT_MAX - si_a) || (si_a < 0 && si_b < INT_MIN - si_a)) {
        printf("Error: Addition would overflow.\n");
        return;
    } else {
        isum = si_a + si_b;
    }
    printf("Sum: %d\n", isum);
}

int main() {
    func(4000000000 , 1000000000); // No wrap , handles error
    return 0;
}
