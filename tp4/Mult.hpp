#ifndef MULT_H
#define MULT_H

#include "Expression.hpp"

class Mult : public Expression {

private:

    Expression * ptrExprA;
    Expression * ptrExprB;

public:

    Mult(const Expression & exprA, const Expression & exprB);

    ~Mult();

    int eval() const override;

    Expression * clone() const override;

};

#endif