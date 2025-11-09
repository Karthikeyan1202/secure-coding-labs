#include <cstdio>
#include <cstdlib>

struct flex_array_struct {
    size_t num;
    int data[];
};

void print_array(const struct flex_array_struct *p) {
    for (size_t i = 0; i < p->num; ++i) std::printf("%d ", p->data[i]);
    std::putchar('\\n');
}

void func(void) {
    size_t n = 4;
    struct flex_array_struct *p = (struct flex_array_struct *)malloc(sizeof(struct flex_array_struct) + sizeof(int)*n);
    if (!p) return;
    p->num = n;
    for (size_t i = 0; i < n; ++i) p->data[i] = (int)i;
    print_array(p);
    free(p);
}

int main() { func(); return EXIT_SUCCESS; }
