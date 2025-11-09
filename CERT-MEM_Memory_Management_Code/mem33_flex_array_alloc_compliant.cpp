#include <cstdio>
#include <cstdlib>

struct flex_array_struct {
    size_t num;
    int data[];
};

void func(void) {
    struct flex_array_struct *flex_struct;
    size_t array_size = 4;
    flex_struct = (struct flex_array_struct *)malloc(sizeof(struct flex_array_struct) + sizeof(int) * array_size);
    if (flex_struct == NULL) return;
    flex_struct->num = array_size;
    for (size_t i = 0; i < array_size; ++i) flex_struct->data[i] = 0;
    free(flex_struct);
}

int main() { func(); std::printf("Flex array allocated successfully\n"); return EXIT_SUCCESS; }
