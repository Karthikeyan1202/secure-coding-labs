#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    const char *source = "computing"; // length 9 + null = 10
    char *copy = (char *) std::malloc(std::strlen(source) + 1); // allocate space for null terminator
    if (copy == nullptr) return 1;
    std::strcpy(copy, source);
    std::printf("%s\n", copy);
    std::free(copy); // free allocated memory to avoid leak
    return 0;
}
