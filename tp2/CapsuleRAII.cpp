#include <iostream>

class CapsuleRAII {

public:

  //Construction, conversion, affectation et destruction
  CapsuleRAII() : ptr(new int) {
    std::cout << "CapsuleRAII::CapsuleRAII()\n";
  }

  // Constructeur PAR COPIE
  CapsuleRAII(const CapsuleRAII & lc) : ptr(new int(*lc.ptr)) {
    std::cout << "CapsuleRAII::CapsuleRAII(const CapsuleRAII & )\n";
  }

  CapsuleRAII(int i) : ptr(new int(i)) {
    std::cout << "CapsuleRAII::CapsuleRAII(int)\n";
  }

  // Constructeur par deplacement
  CapsuleRAII(CapsuleRAII&& c) : ptr(c.ptr) {
    std::cout << "CapsuleRAII::CapsuleRAII(CapsuleRAII&& c)\n";
    c.ptr = nullptr;
  }

  operator bool() const {
    std::cout << "CapsuleRAII::operator bool() const\n";
    return true;
  }

  ~CapsuleRAII() {
    std::cout << "~CapsuleRAII::CapsuleRAII()\n";
    delete ptr;
  }

  // Operateur d'affectation PAR COPIE
  const CapsuleRAII & operator=(const CapsuleRAII & c) {
    std::cout << "CapsuleRAII::operator=(const CapsuleRAII &)\n";
    if (this != &c) {
      if (ptr) delete ptr;
      ptr = new int(*c.ptr);
    }
    return *this;
  }

  // Operateur d'affectation par DEPLACEMENT
  const CapsuleRAII & operator=(CapsuleRAII&& c) {
    std::cout << "CapsuleRAII::operator=(CapsuleRAII&& c)\n";
    if (this != &c) {
      if (ptr) delete ptr;
      ptr = c.ptr;
      c.ptr = nullptr;
    }
    return *this;
  }

  //Autre fonction membre
  CapsuleRAII F(CapsuleRAII);

  // D�claration fonction ext�rieure amie
  friend std::ostream & operator << (std::ostream & os, const CapsuleRAII & lc);

private:
  int* ptr;

};

CapsuleRAII F(CapsuleRAII vv) {
  std::cout << " in F \n";
  return 8;
}

CapsuleRAII CapsuleRAII::F(CapsuleRAII v) {
  std::cout << " in CapsuleRAII::F \n";
  // ::F(v) fait reference a la fonction globale F
  // (pas cette F qui est une fonction membre de CapsuleRAII)
  return ::F(v);
}

std::ostream & operator << (std::ostream & os, const CapsuleRAII & lc) {
  os << " in ostream << CapsuleRAII "<< *lc.ptr << std::endl;
  return os;
}

// Testez et analysez la s�quence d'appels aux fonctions membres 
// de CapsuleRAII dans le programme suivant :


int main() {

  // AVEC OPTION "-fno-elide-constructors"
  // cad SANS OPTIMISATION

  /* =========== NOTES DU TP2 ===========
  Apres avoir declare et defini un constructeur par deplacement
  (rvalue reference), les appels IMPLICITES au constructeur PAR COPIE (la ou
  il y avait une creation d'un temporaire, donc pas partout) sont
  automatiquement remplaces par le constructeur par deplacement (sauf les
  appels explicites au constructeur PAR COPIE).
  De meme, pour les appels a l'operateur d'affectation.
  */

  // A la fois la declaration et l'initialisation (constructeur par defaut)
  CapsuleRAII c1;
  std::cout << std::endl;

  // 1: Un temporaire est cree sur la pile (constructeur par defaut)
  // 2: Initialisation de c2 (constructeur par DEPLACEMENT, avec le temporaire en parametre)
  // REMPLACE en tp2: Constructeur PAR COPIE --> Constructeur PAR DEPLACEMENT
  // 3: Destruction du temporaire (destructeur -> apres destruction reelle)
  CapsuleRAII c2 = CapsuleRAII();
  std::cout << std::endl;

  // Declaration et initialisation (constructeur PAR COPIE, avec c1 en parametre)
  CapsuleRAII cc1(c1);
  std::cout << std::endl;

  // Declaration et initialisation (constructeur PAR COPIE, avec c1 en parametre)
  CapsuleRAII cc2 = c1;
  std::cout << std::endl;

  // 1: Un temporaire est cree sur la pile (constructeur PAR COPIE, avec c1 en parametre)
  // 2: Initialisation de c2 (constructeur par DEPLACEMENT, avec le temporaire en parametre)
  // REMPLACE en tp2: Constructeur PAR COPIE --> Constructeur PAR DEPLACEMENT
  // 3: Destruction du temporaire (destructeur -> apres destruction reelle)
  CapsuleRAII cc3 = CapsuleRAII(c1);
  std::cout << std::endl;

  // Declaration et initialisation (constructeur surcharge, avec un INT en parametre)
  CapsuleRAII cv1(5);
  std::cout << std::endl;

  // 1: Un temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
  // 2: Initialisation de c2 (constructeur par DEPLACEMENT, avec le temporaire en parametre)
  // REMPLACE en tp2: Constructeur PAR COPIE --> Constructeur PAR DEPLACEMENT
  // 3: Destruction du temporaire (destructeur -> apres destruction reelle)
  CapsuleRAII cv2 = 5;
  std::cout << std::endl;

  // 1: Un temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
  // 2: Initialisation de c2 (constructeur par DEPLACEMENT, avec le temporaire en parametre)
  // REMPLACE en tp2: Constructeur PAR COPIE --> Constructeur PAR DEPLACEMENT
  // 3: Destruction du temporaire (destructeur -> apres destruction reelle)
  CapsuleRAII cv3 = CapsuleRAII(5);
  std::cout << std::endl;

  // 1: Un temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
  // 2: Initialisation de c2 (constructeur par DEPLACEMENT, avec le temporaire en parametre)
  // REMPLACE en tp2: Constructeur PAR COPIE --> Constructeur PAR DEPLACEMENT
  // 3: Destruction du temporaire (destructeur -> apres destruction reelle)
  CapsuleRAII cv4 = (CapsuleRAII)5;
  std::cout << std::endl;

  // Operateur = PAR COPIE de c1 avec cc1 en parametre
  c1 = cc1;
  std::cout << std::endl;

  // 1: Un temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
  // 2: AFFECTATION du temporaire a c2 (operateur = PAR DEPLACEMENT de c2 avec le temporaire en parametre)
  // REMPLACE en tp2: operator= PAR COPIE --> operator= PAR DEPLACEMENT
  // 3: Destruction du temporaire (destructeur -> apres destruction reelle)
  c2 = 8;
  std::cout << std::endl;

  // Operateur bool() de cv1
  if(cv1) {

    // 0: Appel a ::F
    // 1: Un temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
    // 2: Initialisation du parametre de la fonction ::F avec le temporaire (constructeur PAR COPIE, avec le temporaire en parametre)
    // 3: On entre dans le corps de ::F
    // 4: Un autre temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
    // 5: Initialisation de la valeur de retour de ::F avec ce nouveau temporaire (constructeur PAR DEPLACEMENT)
    // REMPLACE en tp2: Constructeur PAR COPIE --> Constructeur PAR DEPLACEMENT
    // 6: Destruction de l'objet local a ::F
    // 7: AFFECTATION de la VR de ::F a cv1 (operateur= PAR DEPLACEMENT)
    // REMPLACE en tp2: operator= PAR COPIE --> operator= PAR DEPLACEMENT
    // 8: Destruction de la VR de ::F
    // 9: Destruction du second temporaire
    // 10: Destruction du premier temporaire
    cv1 = F(10);
    std::cout << std::endl;

    // 0: Appel a ::F
    // 1: Initialisation du parametre de la fonction ::F avec c1 (constructeur PAR COPIE, avec c1 en parametre)
    // 2: On entre dans le corps de ::F
    // 3: Un temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
    // 4: Initialisation de la valeur de retour de ::F avec ce temporaire (constructeur PAR DEPLACEMENT)
    // REMPLACE en tp2: Constructeur PAR COPIE --> Constructeur PAR DEPLACEMENT
    // 5: Destruction de l'objet local a ::F
    // 6: AFFECTATION de la VR de ::F a cv1 (operateur= PAR DEPLACEMENT)
    // REMPLACE en tp2: operator= PAR COPIE --> operator= PAR DEPLACEMENT
    // 7: Destruction de la VR de ::F
    // 8: Destruction du temporaire
    cv1 = F(c1);
    std::cout << std::endl;

    // 0: Appel a CapsuleRAII::F
    // 1: Initialisation du parametre de la fonction CapsuleRAII::F avec c2 (constructeur PAR COPIE, avec c2 en parametre)
    // 2: On entre dans le corps de CapsuleRAII::F
    // 3: Appel a ::F
    // 4: Initialisation du parametre de la fonction ::F avec l'objet local a CapsuleRAII::F (constructeur PAR COPIE, avec v en parametre)
    // 5: On entre dans le corps de ::F
    // 6: Un temporaire est cree sur la pile (constructeur surcharge, avec un INT en parametre)
    // 7: Initialisation de la valeur de retour de ::F avec ce temporaire (constructeur PAR DEPLACEMENT)
    // REMPLACE en tp2: Constructeur PAR COPIE --> Constructeur PAR DEPLACEMENT
    // 8: Destruction de l'objet local a ::F
    // 9: Initialisation de la VR de CapsuleRAII::F avec la VR de ::F (constructeur PAR DEPLACEMENT)
    // REMPLACE en tp2: Constructeur PAR COPIE --> Constructeur PAR DEPLACEMENT
    // 10: Destruction de la VR de ::F
    // 11: Destruction du temporaire cree dans ::F
    // 12: AFFECTATION de la VR de CapsuleRAII::F a cv1 (operateur= PAR DEPLACEMENT)
    // REMPLACE en tp2: operator= PAR COPIE --> operator= PAR DEPLACEMENT
    // 13: Destruction de l'objet local a CapsuleRAII::F
    // 14: Destruction de la VR de CapsuleRAII::F
    cv1 = c1.F(c2);
    std::cout << std::endl;
  }

  std::cout << "Tableaux\n";
  CapsuleRAII tab[3];
  std::cout << std::endl;

  CapsuleRAII *pc = new CapsuleRAII(tab[0]);
  std::cout << std::endl;

  delete pc;
  std::cout << std::endl;

  std::cout << "Avant de sortir du main() ... \n";
  
  return 0; 
}
 
