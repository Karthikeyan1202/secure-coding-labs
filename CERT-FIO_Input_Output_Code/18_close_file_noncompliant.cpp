/* FIO42-C: Noncompliant - open file and do not close before returning */
#include <cstdio>
#include <cstdlib>

int func(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (NULL == f) {
        return -1;
    }
    /* Not closing file - resource leak */
    return 0;
}

int main(void) {
    const char *filename = "example.txt";
    if (func(filename) == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    printf("File opened but not closed properly.\n");
    exit(EXIT_SUCCESS);
}
