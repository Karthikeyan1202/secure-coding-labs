/* FIO41-C: Compliant - evaluate side-effecting expressions before calling getc/putc */
#include <cstdio>

void func_compliant(const char *file_name) {
    int c;
    FILE *fptr = fopen(file_name, "r");
    if (fptr == NULL) {
        printf("Error: Unable to open the file.\n");
        return;
    }
    c = getc(fptr);
    if (c == EOF) {
        printf("Compliant Error: End of file reached or a read error occurred.\n");
    } else {
        printf("Compliant code read character: %c\n", c);
    }
    if (fclose(fptr) == EOF) {
        printf("Error: Unable to close the file.\n");
    }
    printf("Compliant code executed successfully.\n");
}

int main() { func_compliant("example.txt"); return 0; }
