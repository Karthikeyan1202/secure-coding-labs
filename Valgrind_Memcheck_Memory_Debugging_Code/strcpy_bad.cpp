#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    const char *source = "computing"; // length 9 + null = 10
    char *copy = (char *) std::malloc(std::strlen(source)); // BUG: no room for null terminator
    // UB: strcpy overruns allocated buffer
    std::strcpy(copy, source);
    std::printf("%s\n", copy);
    // free(copy);  // missing free -> leak
    return 0;
}
