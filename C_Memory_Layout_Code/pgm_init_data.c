/* pgm_init_data.c
 * Initialized data segment example
 */
#include <stdio.h>

int a = 10;
char ch = 'A';
int arr[5] = {1,2,3,4,5};

int main(void) {
    (void)a; (void)ch;
    for (int i = 0; i < 5; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return 0;
}
