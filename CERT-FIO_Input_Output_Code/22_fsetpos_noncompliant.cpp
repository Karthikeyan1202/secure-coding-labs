/* FIO44-C: Noncompliant - using an arbitrary fpos_t instead of one from fgetpos() */
#include <cstdio>
#include <cstring>

int opener(FILE *file) {
    int rc;
    fpos_t offset;
    std::memset(&offset, 0, sizeof(offset)); /* incorrect initialization */

    if (file == NULL) {
        printf("Noncompliant Code: File is NULL.\n");
        return -1;
    }

    /* Attempt to set an invalid position */
    rc = fsetpos(file, &offset);
    if (rc != 0) {
        printf("Noncompliant Code: Error occurred during file position setting (expected failure).\n");
        return rc;
    }
    return 0;
}

int main() {
    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL) {
        printf("Noncompliant Code: File could not be opened (as expected).\n");
        return -1;
    }
    int result = opener(file);
    fclose(file);
    if (result == 0) {
        printf("Noncompliant Code: File position reset (unexpected success).\n");
    }
    return 0;
}
