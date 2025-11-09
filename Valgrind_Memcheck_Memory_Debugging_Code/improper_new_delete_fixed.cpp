#include <iostream>

int main() {
    int *ip = new int(12);
    std::cout << "Value of ip before delete: " << *ip << std::endl;
    delete ip; // CORRECT: use delete for memory allocated with new

    ip = new int(12);
    std::cout << "Value of ip after new allocation: " << *ip << std::endl;
    delete ip;
    return 0;
}
