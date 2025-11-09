#include <iostream>

int main() {
    // WRONG: mixing new and free is undefined behaviour
    int *ip = new int(12);
    std::cout << "Value of ip before free: " << *ip << std::endl;
    std::free(ip); // INCORRECT: should use delete
    return 0;
}
