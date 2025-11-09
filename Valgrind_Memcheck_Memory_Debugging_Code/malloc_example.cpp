#include <iostream>
#include <cstdlib>

int main() {
    int *i_ptr = (int*)std::malloc(sizeof(int) * 10); // Dynamic memory allocation
    if (i_ptr != nullptr) {
        for (int i = 0; i < 10; i++) {
            i_ptr[i] = i; // Assign values to the array
        }
        for (int i = 0; i < 10; i++) {
            std::cout << "Element " << i << ": " << i_ptr[i] << std::endl; // Print array elements
        }
        std::free(i_ptr); // Free allocated memory
    } else {
        std::cerr << "Could not allocate memory\n";
        return 1;
    }
    return 0;
}
