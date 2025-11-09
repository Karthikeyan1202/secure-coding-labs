/* FIO38-C: Noncompliant - copying FILE object by value (bad) */
#include <cstdio>

int main(void) {
    FILE my_stdout = *stdout; /* copying FILE object is undefined behavior */
    if (fputs("Hello, World!\n", &my_stdout) == EOF) {
        printf("Error writing to my_stdout.\n");
    }
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), &my_stdout) == NULL) {
        printf("Error reading from my_stdout.\n");
    } else {
        printf("Read from my_stdout: %s", buffer);
    }
    return 0;
}
