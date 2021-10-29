#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {

public:

    // Constructors cannot be virtual
    Expression();

    // Destructors can and should be virtual for a good memory management
    
    // " virtual " makes a member function and its class POLYMORPHIC (virtual member functions are called METHODS)
    // => when that function will be called via pointer to base class, but that is actually pointing to a derived class
    // then it will call the derived classes version, and not the one of the base class
    virtual ~Expression();

    // " =0 " makes the method PURE VIRTUAL
    // (Declared but without definition, so MUST be defined in derived classes)
    // => A class that has a pure virtual method is called ABSTRACT, and cannot be instantiated
    virtual int eval() const =0;

    virtual Expression * clone() const =0;

};

#endif