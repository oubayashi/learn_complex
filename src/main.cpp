#include "complex.h"
#include <iostream>

int main(int argc, char *argv[])
{
    
    complex c1(2,1);
    complex c2;
    complex* p = new complex(4);
    std::cout << c1.real();
    std::cout << c1.imag();
    return 0;
} 
