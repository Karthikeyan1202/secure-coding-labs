#include <cstdio>
#include <cstdlib>

void f(char *c_str1, size_t size) {
    char *c_str2 = (char *)realloc(c_str1, size);
    if (c_str2 == NULL) {
        free(c_str1); /* potential double-free if realloc freed and returned NULL */
        std::printf("Memory reallocation failed and original freed\n");
    } else {
        std::printf("Memory reallocation successful\n");
    }
}

int main() {
    size_t initial_size = 10;
    char *my_string = (char *)malloc(initial_size);
    if (my_string == NULL) return EXIT_FAILURE;
    std::snprintf(my_string, initial_size, "Hello");
    f(my_string, 0); /* passing size 0 may free inside realloc on some implementations */
    if (my_string) {
        std::printf("String after potential reallocation: %s\n", my_string);
    }
    free(my_string);
    return EXIT_SUCCESS;
}
