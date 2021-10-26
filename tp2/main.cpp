#include "MyString.hpp"
#include <iostream>

int main () {

    const char* chars = "Hello";

    std::cout << chars << std::endl;

    MyString mystr(chars);

    std::cout << mystr << std::endl;

    return 0;
}