/* FIO34-C: Compliant - check feof()/ferror() properly (portable) */
#include <cstdio>

void func(void) {
    int c;
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    do {
        c = fgetc(fp);
        if (c != EOF) {
            printf("Read character: %c\n", c);
        }
    } while (c != EOF || (!feof(fp) && !ferror(fp)));
    fclose(fp);
}

int main() {
    func();
    return 0;
}
