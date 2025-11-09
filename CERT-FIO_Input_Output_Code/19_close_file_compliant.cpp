/* FIO42-C: Compliant - ensure fopen() is matched by fclose() */
#include <cstdio>
#include <cstdlib>

int func(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (NULL == f) {
        return -1;
    }
    /* Simulate operations */
    if (fclose(f) == EOF) {
        return -1;
    }
    return 0;
}

int main(void) {
    const char *filename = "example.txt";
    if (func(filename) == -1) {
        perror("Error opening or closing file");
        exit(EXIT_FAILURE);
    }
    printf("File opened and closed properly.\n");
    exit(EXIT_SUCCESS);
}
