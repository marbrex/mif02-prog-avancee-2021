# mif02-prog-avancee-2021

* [x] **TP1** Constructeurs, destructeurs, temporaires et conversions.
* [x] **TP2** Capsule RAII, déplacement, affectation des classes dérivées, upcast et downcast, écriture d'une classe String.
* [x] **TP3** Objets fonctions, Polymorphisme.
* [x] **TP4** Polymorphisme.
* [ ] **TP5** Template.
* [ ] **TP6** Template, itérateurs et STL.
* [ ] **TP7** Template, itérateurs, Inserteurs, STL, déplacement.
* [ ] **TP8** Métaprogrammation, Const_cast.

> Useful commands:
> - ```g++ -fno-elide-constructors -Wall -std=c++11 -ggdb -o exec CapsuleRAII.cpp```\
The **-ggdb** option of g++ for debugging with Valgrind. With that option Valgrind will show the exact lines where a leak happened.
> - ```valgrind --tool=memcheck --leak-check=full --track-origins=yes --verbose ./exec```

> ### Bottom Line:
> 
> ### `virtual`
> makes a member function and its class **POLYMORPHIC** (virtual member functions are called METHODS)
> 
> => **POLYMORPHISM**
> when a polymorphic function is called via pointer or reference of base class type, but that is actually pointing to one of its derived classes
> it will call the derived classes version, and not the one of the base class.
> 
> - Virtual functions should be accessed using **pointer** or **reference** of base class type to achieve run time polymorphism.
> - The prototype of virtual functions should be the same in the base as well as derived class.
> - It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.
> - A class may have **virtual destructor** but it cannot have a virtual constructor.
> 
> ```cpp
> class Enemy {
> public:
> 	virtual void attack() {
> 		std::cout << "Enemy attacks!" << std::endl;
> 	}
> };
> 
> class Monster : public Enemy {
> public:
> 	void attack() {
> 		std::cout << "Monster attacks!" << std::endl;
> 	}
> };
> 
> int main() {
> 	Monster m;
> 	
> 	Enemy* ptrE = &m;
> 	ptrE->attack(); // Prints "Monster attacks!"
> 	
> 	Enemy& refE = m;
> 	refE.attack(); // Prints "Monster attacks!"
> 	
> 	Enemy e = m;
> 	e.attack(); // Prints "Enemy attacks!";
> 	
> 	return 0;
> }
> ```
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
> explicitly indicating that the function is a **redefinition**.
> Is used to avoid problems with masking base class's functions.
> 
> ---
> 
> ### `using`
> Is used to avoid problems with masking base class's functions.
> 
> > **Masking / Dominance** : Inheritance relies on a basic mechanism called Masking or Dominance, which states that a definition of a derived class D of B corresponds to introduction of a new scope that dominates over the one of B.
> > Thus, an identifier *F* in the scope of D, hides all the same identifiers inherited from B.
> > Masking is **based only on the identifiers** and **not the type** !
> 
> => Brings ALL `Base::f` out of the hidden scope
> ```cpp
> class B {
> public:
> 	void f(int) {
> 		std::cout << "void B::f(int)" << std::endl;
> 	}
> 	void f(double) {
> 		std::cout << "void B::f(double)" << std::endl;
> 	}
> };
> 
> class D : public B {
> public:
> 	// here f is an overload of f, and not the redefinition
> 	int f(int, int) {
> 		std::cout << "int D::f(int, int)" << std::endl;
> 	}
> 	using B::f; // brings ALL B::f out of the hidden scope
> };
> 
> int main() {
> 	D d; 
> 	d.f(3);
> 	// OK with 'using'
> 	// Otherwise ERROR: no matching function for call to 'D::f(int)'
> 	
> 	return 0;
> }
> ```
> 
> ---
> 
> ### `explicit`
> Prohibits an implicit conversion when a member function prefixed with `explicit` is called.
> 
> ---
> 
> ### `=default`
> Explicitly indicates that the member function's declaration postfixed with `=default`, should use the implementation proposed by the compiler by default.
> - Can be used only with special member functions
> ```cpp
> struct LaClasse {
> 	LaClasse() =default; //C++11
> 	~LaClasse() =default; //C++11
> 	// … blablacode …
> };
> ```
> 
> ---
> 
> ### `=delete`
> Explicitly indicates that the implementation proposed by the compiler by default of the member function declared with `=delete`, should be removed.
> ```cpp
> class A {
> private:
> 	int n;
> public:
> 	A(int x) : n(x) {}
> 	
> 	A(double) =delete;
> 	
> 	// Delete the copy constructor
> 	A(const A&) =delete;
> 	
> 	// Delete the copy assignment operator
> 	A& operator=(const A&) =delete;
> };
> 
> int main() {
>     A a1(1), a2(2), a3(3);
>     
>     // Error, disabled
>     A a4(3.14);
>      
>     // Error, the usage of the copy
>     // assignment operator is disabled
>     a1 = a2;
>      
>     // Error, the usage of the
>     // copy constructor is disabled
>     a3 = A(a2);
>     return 0;
> }
> ```
> 
> ---
> 
> ### `final`
> => A final class cannot be derived.
> 