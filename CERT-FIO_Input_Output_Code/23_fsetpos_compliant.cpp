/* FIO44-C: Compliant - call fgetpos() and later fsetpos() with the returned value */
#include <cstdio>

int opener(FILE *file) {
    int rc;
    fpos_t offset;

    if (file == NULL) {
        return -1;
    }

    rc = fgetpos(file, &offset);
    if (rc != 0) {
        return rc;
    }

    /* simulated operations */

    rc = fsetpos(file, &offset);
    if (rc != 0) {
        return rc;
    }

    return 0;
}

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        return -1;
    }
    int result = opener(file);
    fclose(file);
    if (result == 0) {
        printf("Compliant Code: File position successfully reset.\n");
    } else {
        printf("Compliant Code: Error occurred during file position setting.\n");
    }
    return 0;
}
