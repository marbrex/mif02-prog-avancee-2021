#include "Constante.hpp"
#include "Plus.hpp"
#include "Moins.hpp"
#include "Mult.hpp"

#include <iostream>

int main() {

    int a = 5;

    Constante c1(a);
    std::cout << std::endl;

    Constante c2(-2);
    std::cout << std::endl;

    Constante c3(1);
    std::cout << std::endl;

    Constante c4(3);
    std::cout << std::endl;

    Plus p1(c1, c2);
    std::cout << std::endl;

    Plus p2(c3, c4);
    std::cout << std::endl;

    const Expression & e = Mult(p1, p2);
    std::cout << std::endl;
    
    std::cout << e.eval() << std::endl;

    return 0;
}