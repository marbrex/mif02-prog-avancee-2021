#include <iostream>

#include "Generator.hpp"

int main() {

    Generator g(6);
    std::cout << g() << std::endl;
    std::cout << g() << std::endl;
    std::cout << g() << std::endl;

    return 0;
}