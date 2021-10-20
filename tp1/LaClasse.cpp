#include <iostream>

class LaClasse {

public:

  //Construction, conversion, affectation et destruction
  LaClasse() : l(0) {
    std::cout << "LaClasse::LaClasse()\n";
  }

  LaClasse(const LaClasse & lc) : l(lc.l) {
    std::cout << "LaClasse::LaClasse(const LaClasse & )\n";
  }

  LaClasse(int i) : l(i) {
    std::cout << "LaClasse::LaClasse(int)\n";
  }

  operator bool() const {
    std::cout << "LaClasse::operator bool() const\n";
    return true;
  }

  ~LaClasse() {
    std::cout << "~LaClasse::LaClasse()\n";
  }

  const LaClasse & operator=(const LaClasse & c) {
    l = c.l;
    std::cout << "LaClasse::operator=(const LaClasse &)\n";
    return *this;
  }

  //Autre fonction membre
  LaClasse F(LaClasse);

  // D�claration fonction ext�rieure amie
  friend std::ostream & operator << (std::ostream & os, const LaClasse & lc);

private:
  int l;

};

LaClasse F(LaClasse vv) {
  std::cout << " in F \n";
  return 8;
}

LaClasse LaClasse::F(LaClasse v) {
  std::cout << " in LaClasse::F \n";
  // ::F(v) fait reference a la fonction globale F
  // (pas cette F qui est une fonction membre de LaClasse)
  return ::F(v);
}

std::ostream & operator << (std::ostream & os, const LaClasse & lc) {
  os << " in ostream << LaClasse "<< lc.l << std::endl;
  return os;
}

// Testez et analysez la s�quence d'appels aux fonctions membres 
// de LaClasse dans le programme suivant :


int main() {

  // AVEC OPTION "-fno-elide-constructors"
  // cad SANS OPTIMISATION

  // A la fois la declaration et l'initialisation (constructeur par defaut)
  LaClasse c1;
  std::cout << std::endl;

  // 1: Un temporaire est cree sur la pile (constructeur par defaut)
  // 2: Initialisation de c2 (constructeur par copie, avec le temporaire en parametre)
  // 3: Destruction du temporaire (destructeur -> apres destruction reelle)
  LaClasse c2 = LaClasse();
  std::cout << std::endl;

  // Declaration et initialisation (constructeur par copie, avec c1 en parametre)
  LaClasse cc1(c1);
  std::cout << std::endl;

  // Declaration et initialisation (constructeur par copie, avec c1 en parametre)
  LaClasse cc2 = c1;
  std::cout << std::endl;

  // 1: Un temporaire est cree sur la pile (constructeur par copie, avec c1 en parametre)
  // 2: Initialisation de c2 (constructeur par copie, avec le temporaire en parametre)
  // 3: Destruction du temporaire (destructeur -> apres destruction reelle)
  LaClasse cc3 = LaClasse(c1);
  std::cout << std::endl;

  // Declaration et initialisation (constructeur surcharge, avec un INT en parametre)
  LaClasse cv1(5);
  std::cout << std::endl;

  // 1: Un temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
  // 2: Initialisation de c2 (constructeur par copie, avec le temporaire en parametre)
  // 3: Destruction du temporaire (destructeur -> apres destruction reelle)
  LaClasse cv2 = 5;
  std::cout << std::endl;

  // 1: Un temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
  // 2: Initialisation de c2 (constructeur par copie, avec le temporaire en parametre)
  // 3: Destruction du temporaire (destructeur -> apres destruction reelle)
  LaClasse cv3 = LaClasse(5);
  std::cout << std::endl;

  // 1: Un temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
  // 2: Initialisation de c2 (constructeur par copie, avec le temporaire en parametre)
  // 3: Destruction du temporaire (destructeur -> apres destruction reelle)
  LaClasse cv4 = (LaClasse)5;
  std::cout << std::endl;

  // Operateur = de c1 avec cc1 en parametre
  c1 = cc1;
  std::cout << std::endl;

  // 1: Un temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
  // 2: AFFECTATION du temporaire a c2 (operateur = de c2 avec le temporaire en parametre)
  // 3: Destruction du temporaire (destructeur -> apres destruction reelle)
  c2 = 8;
  std::cout << std::endl;

  // Operateur bool() de cv1
  if(cv1) {

    // 0: Appel a ::F
    // 1: Un temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
    // 2: Initialisation du parametre de la fonction ::F avec le temporaire (constructeur par copie, avec le temporaire en parametre)
    // 3: On entre dans le corps de ::F
    // 4: Un autre temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
    // 5: Initialisation de la valeur de retour de ::F avec ce nouveau temporaire (constructeur par copie)
    // 6: Destruction de l'objet local a ::F
    // 7: AFFECTATION de la VR de ::F a cv1 (operateur=)
    // 8: Destruction de la VR de ::F
    // 9: Destruction du second temporaire
    // 10: Destruction du premier temporaire
    cv1 = F(10);
    std::cout << std::endl;

    // 0: Appel a ::F
    // 1: Initialisation du parametre de la fonction ::F avec c1 (constructeur par copie, avec c1 en parametre)
    // 2: On entre dans le corps de ::F
    // 3: Un temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
    // 4: Initialisation de la valeur de retour de ::F avec ce temporaire (constructeur par copie)
    // 5: Destruction de l'objet local a ::F
    // 6: AFFECTATION de la VR de ::F a cv1 (operateur=)
    // 7: Destruction de la VR de ::F
    // 8: Destruction du temporaire
    cv1 = F(c1);
    std::cout << std::endl;

    // 0: Appel a LaClasse::F
    // 1: Initialisation du parametre de la fonction LaClasse::F avec c2 (constructeur par copie, avec c2 en parametre)
    // 2: On entre dans le corps de LaClasse::F
    // 3: Appel a ::F
    // 4: Initialisation du parametre de la fonction ::F avec l'objet local a LaClasse::F (constructeur par copie, avec v en parametre)
    // 5: On entre dans le corps de ::F
    // 6: Un temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
    // 7: Initialisation de la valeur de retour de ::F avec ce temporaire (constructeur par copie)
    // 8: Destruction de l'objet local a ::F
    // 9: Initialisation de la VR de LaClasse::F avec la VR de ::F (constructeur par copie)
    // 10: Destruction de la VR de ::F
    // 11: Destruction du temporaire cree dans ::F
    // 12: AFFECTATION de la VR de LaClasse::F a cv1 (operateur=)
    // 13: Destruction de l'objet local a LaClasse::F
    // 14: Destruction de la VR de LaClasse::F
    cv1 = c1.F(c2);
    std::cout << std::endl;
  }

  std::cout << "Tableaux\n";
  LaClasse tab[3];
  std::cout << std::endl;

  LaClasse *pc = new LaClasse(tab[0]);
  std::cout << std::endl;

  delete pc;
  std::cout << std::endl;

  std::cout << "Avant de sortir du main() ... \n";
  
  return 0; 
}
 
