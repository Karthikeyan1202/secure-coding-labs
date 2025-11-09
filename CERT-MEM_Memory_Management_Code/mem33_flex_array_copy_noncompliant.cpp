#include <cstdio>
#include <cstdlib>

struct flex_array_struct {
    size_t num;
    int data[];
};

void func(struct flex_array_struct *a, struct flex_array_struct *b) {
    *b = *a; /* shallow copy - does not copy flexible array content correctly */
}

int main() {
    size_t n = 4;
    struct flex_array_struct *a = (struct flex_array_struct *)malloc(sizeof(struct flex_array_struct) + sizeof(int)*n);
    struct flex_array_struct *b = (struct flex_array_struct *)malloc(sizeof(struct flex_array_struct) + sizeof(int)*n);
    if (!a || !b) return EXIT_FAILURE;
    a->num = n;
    for (size_t i = 0; i < n; ++i) a->data[i] = i+1;
    func(a, b);
    std::printf("struct_b num: %zu\n", b->num);
    free(a); free(b);
    return EXIT_SUCCESS;
}
