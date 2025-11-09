#include <cstdio>
#include <cstdlib>

void f(char *c_str1, size_t size) {
    if (size != 0) {
        char *c_str2 = (char *)realloc(c_str1, size);
        if (c_str2 == NULL) {
            free(c_str1);
        } else {
            /* Use c_str2 or assign back to caller-managed pointer */
        }
    } else {
        /* Intent: free when size == 0 */
        free(c_str1);
    }
}

int main() {
    size_t initial_size = 10;
    char *my_string = (char *)malloc(initial_size);
    if (my_string == NULL) return EXIT_FAILURE;
    std::snprintf(my_string, initial_size, "Hello");
    f(my_string, 20);
    std::printf("String after potential reallocation: %s\n", my_string);
    free(my_string);
    return EXIT_SUCCESS;
}
