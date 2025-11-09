#include <cstdio>
#include <cstdlib>
#include <cstring>

struct flex_array_struct {
    size_t num;
    int data[];
};

void func(struct flex_array_struct *a, struct flex_array_struct *b) {
    if (a->num > b->num) return;
    std::memcpy(b, a, sizeof(struct flex_array_struct) + (sizeof(int) * a->num));
}

int main() {
    size_t na = 4, nb = 4;
    struct flex_array_struct *a = (struct flex_array_struct *)malloc(sizeof(struct flex_array_struct) + sizeof(int)*na);
    struct flex_array_struct *b = (struct flex_array_struct *)malloc(sizeof(struct flex_array_struct) + sizeof(int)*nb);
    if (!a || !b) return EXIT_FAILURE;
    a->num = na;
    for (size_t i = 0; i < na; ++i) a->data[i] = (int)(i+1);
    b->num = nb;
    func(a, b);
    std::printf("struct_b num: %zu\n", b->num);
    for (size_t i = 0; i < b->num; ++i) std::printf("struct_b data[%zu]: %d\n", i, b->data[i]);
    free(a); free(b);
    return EXIT_SUCCESS;
}
