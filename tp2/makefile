# cible: liste des dependences <EOL>
# <TAB> commande
all: executable.out

# Edition de liens (construit l’executable grace aux fichiers objets et aux bibliotheques externes).
# Les dependances d’un executable sont les .o du projet.
executable.out: main.o MyString.o
	g++ -g main.o MyString.o -o executable.out

# 1) Le preprocesseur traite les directives (ex. #include et #define)
#    --> .i (fichiers source completes)
# 2) Le compilateur traduit les fichiers en langage d’assemblage
#    --> .s (fichiers en langage d'assemblage)
# 3) Le compilateur traduit les fichiers assemblage en langage machine
#    --> .o (fichiers objets en langage machine)

# Les dependances d’un .o sont les fichiers .h et .cpp du module et les .h utilises par le module.
# Les dependances .h et .o ne sont pas des cibles dans le Makefile, ce sont des fichiers.
# make regarde si au moins un de ces fichiers est plus récent que main.o.
main.o: main.cpp MyString.hpp
	g++ -g -c main.cpp

MyString.o: MyString.hpp MyString.cpp
	g++ -g -c MyString.cpp




clean:
	rm *.o

veryclean: clean
	rm *.out