#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "Expression.hpp"

class Constante : public Expression {

private:

    int value;

public:

    Constante(int i);

    ~Constante();

    // " override " montre que cette fonction de la partie heritee DOIT ETRE RE-DEFINIE
    // => pour eviter les problemes de masquage
    int eval() const override;

    Expression * clone() const override;

};

#endif