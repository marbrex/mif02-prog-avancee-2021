#ifndef MOINS_H
#define MOINS_H

#include "Expression.hpp"

class Moins : public Expression {

private:

    Expression * ptrExprA;
    Expression * ptrExprB;

public:

    Moins(const Expression & exprA, const Expression & exprB);

    ~Moins();

    int eval() const override;

    Expression * clone() const override;

};

#endif