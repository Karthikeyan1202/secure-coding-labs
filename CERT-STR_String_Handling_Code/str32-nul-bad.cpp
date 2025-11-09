#include <cstdio>
#include <cstring>
void fn_bad(const char *name) {
    char filename[20];
    // noncompliant: snprintf return check missing and potential mismatch causing undefined behavior
    std::snprintf(filename, sizeof(filename), "%s.txt", name);
    // If name not null-terminated or too long, behavior may be unexpected
    std::printf("filename: %s\n", filename);
}
int main() {
    fn_bad("a_very_long_filename_example_exceeding_buffer");
    return 0;
}
