#include <cstdio>
#include <cstdlib>
#include <cstring>
int main(int argc, char *argv[]) {
    const char *name = (argc && argv[0]) ? argv[0] : "";
    size_t len = std::strlen(name) + 1;
    char *copy = (char *)std::malloc(len);
    if (!copy) { std::perror("malloc"); return 1; }
    std::memcpy(copy, name, len);
    std::printf("%s\n", copy);
    std::free(copy);
    return 0;
}
