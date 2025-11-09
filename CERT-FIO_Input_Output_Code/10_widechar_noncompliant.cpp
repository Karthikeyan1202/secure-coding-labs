/* FIO34-C: Noncompliant wide-char example - using wchar_t for getwc() return */
#include <cstdio>
#include <wchar.h>

enum { BUFFER_SIZE = 32 };

void g(void) {
    wchar_t buf[BUFFER_SIZE];
    wchar_t wc;
    size_t i = 0;
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    while ((wc = getwc(fp)) != L'\n' && wc != WEOF) {
        if (i < BUFFER_SIZE - 1) {
            buf[i++] = wc;
            wprintf(L"Read wide character: %lc\n", wc);
        }
    }
    buf[i] = L'\0';
    fclose(fp);
}

int main() { g(); return 0; }
