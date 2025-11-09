/* sum_avg.c
 * Simple functions to illustrate stack usage across calls
 */
#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

float avg(int a, int b) {
    int s = sum(a, b);
    return (float)s / 2.0f;
}

int main(void) {
    int a = 10, b = 20;
    printf("Average of %d and %d = %f\n", a, b, avg(a, b));
    return 0;
}
