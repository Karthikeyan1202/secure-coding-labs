#include <cstdio>
#include <cstring>
void fn_fix(const char *name) {
    char filename[20];
    int r = std::snprintf(filename, sizeof(filename), "%.15s.txt", name);
    if (r < 0 || (size_t)r >= sizeof(filename)) {
        std::fprintf(stderr, "filename truncated or error\\n");
        return;
    }
    std::printf("filename: %s\n", filename);
}
int main() {
    fn_fix("a_very_long_filename_example_exceeding_buffer");
    return 0;
}
