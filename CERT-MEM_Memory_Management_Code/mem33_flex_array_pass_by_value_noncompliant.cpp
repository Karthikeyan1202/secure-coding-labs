#include <cstdio>
#include <cstdlib>

struct flex_array_struct {
    size_t num;
    int data[];
};

void print_array(struct flex_array_struct struct_p) { /* copies only header, not flexible array contents properly */
    for (size_t i = 0; i < struct_p.num; ++i) {
        std::printf("%d ", struct_p.data[i]);
    }
    std::putchar('\\n');
}

void func(void) {
    size_t n = 4;
    struct flex_array_struct *p = (struct flex_array_struct *)malloc(sizeof(struct flex_array_struct) + sizeof(int)*n);
    if (!p) return;
    p->num = n;
    for (size_t i = 0; i < n; ++i) p->data[i] = (int)i;
    print_array(*p); /* problematic: passing by value */
    free(p);
}

int main() { func(); return EXIT_SUCCESS; }
