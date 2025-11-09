/* FIO41-C: Noncompliant - passing expression with side effects as stream argument */
#include <cstdio>

void func_non_compliant(const char *file_name) {
    FILE *fptr;
    int c = getc(fptr = fopen(file_name, "r")); /* if getc is a macro, fopen may be called multiple times */
    if (fptr == NULL) {
        printf("Error: Unable to open the file.\n");
        return;
    }
    if (feof(fptr) || ferror(fptr)) {
        printf("Non-compliant Error: End of file reached or a read error occurred.\n");
    }
    if (fclose(fptr) == EOF) {
        printf("Error: Unable to close the file.\n");
    }
    printf("Non-compliant code executed.\n");
}

int main() { func_non_compliant("example.txt"); return 0; }
