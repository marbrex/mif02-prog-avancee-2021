#include "Moins.hpp"

#include <iostream>

Moins::Moins(const Expression & exprA, const Expression & exprB) : ptrExprA(exprA.clone()), ptrExprB(exprB.clone()) {
    std::cout << "Moins::Moins(const Expression & exprA, const Expression & exprB)" << std::endl;
}

Moins::~Moins() {
    std::cout << "Moins::~Moins()\n";
    delete ptrExprA;
    delete ptrExprB;
}

int Moins::eval() const {
    return ptrExprA->eval() - ptrExprB->eval();
}

Expression * Moins::clone() const {
    return new Moins(*ptrExprA, *ptrExprB);
}