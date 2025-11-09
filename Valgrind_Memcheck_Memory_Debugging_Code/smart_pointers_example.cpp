#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> p1 = std::make_shared<int>(5);
    std::shared_ptr<int> p2 = p1;
    std::cout << "Value: " << *p1 << std::endl;
    p1.reset();
    if (!p1) { std::cout << "p1 is null after reset." << std::endl; }
    std::cout << "Value after p1 reset, accessed via p2: " << *p2 << std::endl;
    p2.reset();
    if (!p2) { std::cout << "p2 is null after reset." << std::endl; }
    return 0;
}
