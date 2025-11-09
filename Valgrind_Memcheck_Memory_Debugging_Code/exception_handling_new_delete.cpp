#include <iostream>
#include <new>

int main()
{
    try
    {
        int *pn = new int;          // Allocate memory for a single integer
        int *pi = new int(5);       // Allocate memory and initialize to 5
        double *pd = new double(55.9);  // Allocate memory and initialize to 55.9
        int *buf = new int[10];     // Allocate memory for an array of 10 integers

        *pn = 10;  // Assign value to pn

        std::cout << "Value of pn: " << *pn << std::endl;
        std::cout << "Value of pi: " << *pi << std::endl;
        std::cout << "Value of pd: " << *pd << std::endl;
        // Initialize the array to avoid garbage values
        for (int i = 0; i < 10; i++) { buf[i] = i; }
        for (int i = 0; i < 10; i++) { std::cout << "buf[" << i << "]: " << buf[i] << std::endl; }

        delete pn;
        delete pi;
        delete pd;
        delete[] buf;
    }
    catch (std::bad_alloc& e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
