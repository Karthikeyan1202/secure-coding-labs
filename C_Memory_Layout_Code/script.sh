#!/bin/bash
# extract_memlayout_c.sh
# Create small, clean .c example files from the C_Memory_Layout.pdf examples.
# Usage: chmod +x extract_memlayout_c.sh && ./extract_memlayout_c.sh

set -euo pipefail

cat > pgm_init_data.c <<'EOF'
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
EOF

cat > pgm_bss.c <<'EOF'
/* pgm_bss.c
 * Uninitialized (BSS) segment example
 */
#include <stdio.h>

int a, b, c;
char ch;

int main(void) {
    printf("a=%d b=%d c=%d ch=%d\n", a, b, c, (int)ch);
    return 0;
}
EOF

cat > infi_loop.c <<'EOF'
/* infi_loop.c
 * Infinite loop (used to examine resource/stack behaviour)
 */
int main(void) {
    for (;;) { } /* intentional infinite loop */
    return 0;
}
EOF

cat > stack_limits.c <<'EOF'
/* stack_limits.c
 * Query stack limits using getrlimit()
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/resource.h>

int main(void) {
    struct rlimit lim;
    if (getrlimit(RLIMIT_STACK, &lim) == 0) {
        printf("Soft stack limit = %ld\n", (long)lim.rlim_cur);
        printf("Hard stack limit = %ld\n", (long)lim.rlim_max);
    } else {
        printf("getrlimit failed: %s\n", strerror(errno));
        return 1;
    }
    return 0;
}
EOF

cat > sum_avg.c <<'EOF'
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
EOF

cat > copy_strncpy.c <<'EOF'
/* copy_strncpy.c
 * Safe copy using strncpy with explicit NUL termination
 */
#include <stdio.h>
#include <string.h>

void copy_in(const char *src) {
    char name[10];
    /* copy at most sizeof(name)-1 and ensure termination */
    strncpy(name, src, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
    printf("Copied name: %s\n", name);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        copy_in(argv[1]);
    } else {
        printf("No argument provided\n");
    }
    return 0;
}
EOF

cat > heap_demo.c <<'EOF'
/* heap_demo.c
 * Demonstrates heap allocation vs stack variable addresses
 */
#include <stdio.h>
#include <stdlib.h>

int func(void) {
    int a = 10;
    int *aptr = &a;
    int *ptr = (int *)malloc(sizeof(int));
    if (!ptr) return -1;
    *ptr = 20;
    printf("Heap value = %d\n", *ptr);
    printf("Stack value (via pointer) = %d\n", *aptr);
    free(ptr);
    return 0;
}

int main(void) {
    func();
    return 0;
}
EOF

echo "Created files:"
ls -1 *.c
echo
echo "To compile all examples quickly run:"
echo "  gcc -std=c11 -Wall -Wextra *.c -o mem_examples"

