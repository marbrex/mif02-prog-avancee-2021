#ifndef PLUS_H
#define PLUS_H

#include "Expression.hpp"

class Plus : public Expression {

private:

    Expression * ptrExprA;
    Expression * ptrExprB;

public:

    Plus(const Expression & exprA, const Expression & exprB);

    ~Plus();

    int eval() const override;

    Expression * clone() const override;

};

#endif