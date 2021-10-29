# mif02-prog-avancee-2021

* [x] **TP1** Constructeurs, destructeurs, temporaires et conversions.
* [x] **TP2** Capsule RAII, déplacement, affectation des classes dérivées, upcast et downcast, écriture d'une classe String.

> Useful commands:
> - ```g++ -fno-elide-constructors -Wall -std=c++11 -ggdb -o exec CapsuleRAII.cpp```\
The **-ggdb** option of g++ for debugging with Valgrind. With that option Valgrind will show the exact lines where a leak happened.
> - ```valgrind --tool=memcheck --leak-check=full --track-origins=yes --verbose ./exec```

* [x] **TP3** Objets fonctions, Polymorphisme.
* [x] **TP4** Polymorphisme.

> ### Bottom Line:
> ### `virtual`
> makes a member function and its class **POLYMORPHIC** (virtual member functions are called METHODS)
> 
> => **POLYMORPHISM**
> when a polymorphic function is called via pointer or reference of base class type, but that is actually pointing to one of its derived classes
> it will call the derived classes version, and not the one of the base class.
> 
> - Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism.
> - The prototype of virtual functions should be the same in the base as well as derived class.
> - It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.
> - A class may have **virtual destructor** but it cannot have a virtual constructor.
> 
> ---
> 
> ### `=0`
> makes the method **PURE VIRTUAL**
> Declared but without definition, so MUST be defined in the derived classes.
> 
> => A class that has a pure virtual method is called **ABSTRACT**, and cannot be directly instantiated !
> 
> - Must be overriden in the derived classes.
> - If we do not override the pure virtual function in derived class, then derived class also becomes abstract class.
> - We can have pointers and references whose static type is an abstract class type.
>
> ---
> 
> ### `override`
> explicitly indicating that the function is a redefinition.
> Is used to avoid problems with masking base class's functions.
> 
> ---
> 
> ### `=delete`
> 
> ---
> 
> ### `final`
> A final class cannot be derived.
> 

* [ ] **TP5** Template.
* [ ] **TP6** Template, itérateurs et STL.
* [ ] **TP7** Template, itérateurs, Inserteurs, STL, déplacement.
* [ ] **TP8** Métaprogrammation, Const_cast.