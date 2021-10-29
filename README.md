# mif02-prog-avancee-2021

* [x] **TP1** Constructeurs, destructeurs, temporaires et conversions.
* [x] **TP2** Capsule RAII, déplacement, affectation des classes dérivées, upcast et downcast, écriture d'une classe String.
> Useful commands:
> - ```g++ -fno-elide-constructors -Wall -std=c++11 -ggdb -o exec CapsuleRAII.cpp```\
The **-ggdb** option of g++ for debugging with Valgrind. With that option Valgrind will show the exact lines where a leak happened.
> - ```valgrind --tool=memcheck --leak-check=full --track-origins=yes --verbose ./exec```
* [x] **TP3** Objets fonctions, Polymorphisme.
* [ ] **TP4** Polymorphisme.
* [ ] **TP5** Template.
* [ ] **TP6** Template, itérateurs et STL.
* [ ] **TP7** Template, itérateurs, Inserteurs, STL, déplacement.
* [ ] **TP8** Métaprogrammation, Const_cast.