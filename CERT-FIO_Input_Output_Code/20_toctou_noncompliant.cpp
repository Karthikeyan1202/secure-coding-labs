/* FIO45-C: Noncompliant TOCTOU - check-then-open pattern creates race window */
#include <cstdio>

void open_some_file(const char *file) {
    FILE *f = fopen(file, "r"); /* check if file exists */
    if (f != NULL) {
        printf("Noncompliant Code: File exists. Not overwriting.\n");
        fclose(f);
    } else {
        f = fopen(file, "w"); /* race window exists here */
        if (f == NULL) {
            printf("Noncompliant Code: Failed to open file for writing.\n");
        } else {
            printf("Noncompliant Code: Writing to file.\n");
            if (fclose(f) == EOF) {
                printf("Noncompliant Code: Error closing file.\n");
            }
        }
    }
}

int main() {
    open_some_file("example.txt");
    return 0;
}
