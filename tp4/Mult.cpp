#include "Mult.hpp"

#include <iostream>

Mult::Mult(const Expression & exprA, const Expression & exprB) : ptrExprA(exprA.clone()), ptrExprB(exprB.clone()) {
    std::cout << "Mult::Mult(const Expression & exprA, const Expression & exprB)" << std::endl;
}

Mult::~Mult() {
    std::cout << "Mult::~Mult()\n";
    delete ptrExprA;
    delete ptrExprB;
}

int Mult::eval() const {
    return ptrExprA->eval() * ptrExprB->eval();
}

Expression * Mult::clone() const {
    return new Mult(*ptrExprA, *ptrExprB);
}