/* FIO34-C: Compliant wide-char example - use wint_t for getwc() return */
#include <cstdio>
#include <wchar.h>

enum { BUFFER_SIZE = 32 };

void g(void) {
    wchar_t buf[BUFFER_SIZE];
    wint_t wc;
    size_t i = 0;
    FILE *fp = fopen("wide_input.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    while ((wc = getwc(fp)) != L'\n' && wc != WEOF) {
        if (i < BUFFER_SIZE - 1) {
            buf[i++] = (wchar_t)wc;
            wprintf(L"Read wide character: %lc\n", (wchar_t)wc);
        }
    }
    if (feof(fp) || ferror(fp)) {
        buf[i] = L'\0';
        printf("End of file or error encountered.\n");
    } else {
        printf("Received a wide character matching WEOF; handling error.\n");
    }
    fclose(fp);
}

int main() { g(); return 0; }
