#include <cstdio>
#include <wchar.h>
#include <stdlib.h>
int main() {
    wchar_t wsrc[] = L"0123456789";
    size_t n = wcslen(wsrc) + 1;
    wchar_t *dest = (wchar_t *)std::malloc(n * sizeof(wchar_t));
    if (!dest) { std::perror("malloc"); return 1; }
    wcscpy(dest, wsrc); // correct: use wide-string functions for wide data
    std::wprintf(L"Copied wide string: %ls\n", dest);
    std::free(dest);
    return 0;
}
