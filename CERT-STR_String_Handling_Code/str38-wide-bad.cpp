#include <cstdio>
#include <wchar.h>
#include <string.h>
int main() {
    // noncompliant: mixing narrow/wide APIs (illustration of wrong usage)
    wchar_t wsrc[] = L"0123456789";
    // incorrect: passing wide buffer to strncpy (narrow function)
    // strncpy((char*)wsrc, "abcd", 4); // DO NOT DO THIS
    std::printf("Bad wide/narrow mixing is undefined behavior (example suppressed).\n");
    return 0;
}
