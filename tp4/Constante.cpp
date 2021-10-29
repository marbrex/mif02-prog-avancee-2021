#include "Constante.hpp"

#include <iostream>

Constante::Constante(int i) : value(i) {
    std::cout << "Constante::Constante(int i)" << std::endl;
}

Constante::~Constante() {
    std::cout << "Constante::~Constante()" << std::endl;
}

int Constante::eval() const { return value; }

Expression * Constante::clone() const {
    return new Constante(value);
}