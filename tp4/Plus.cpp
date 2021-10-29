#include "Plus.hpp"

#include <iostream>

Plus::Plus(const Expression & exprA, const Expression & exprB) : ptrExprA(exprA.clone()), ptrExprB(exprB.clone()) {
    std::cout << "Plus::Plus(const Expression & exprA, const Expression & exprB)" << std::endl;
}

Plus::~Plus() {
    std::cout << "Plus::~Plus()\n";
    delete ptrExprA;
    delete ptrExprB;
}

int Plus::eval() const {
    return ptrExprA->eval() + ptrExprB->eval();
}

Expression * Plus::clone() const {
    return new Plus(*ptrExprA, *ptrExprB);
}