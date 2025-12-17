
OPTIONS = -ansi -pedantic -Wall -std=c++11

ifdef MAP
    OPTIONS += -DMAP
endif

trajets: main.o Catalogue.o TrajetSimple.o TrajetCompose.o Trajet.o Noeud.o
	g++ -o trajets main.o Catalogue.o TrajetSimple.o TrajetCompose.o Trajet.o Noeud.o $(OPTIONS)

main.o: main.cpp
	g++ -c main.cpp $(OPTIONS)

Catalogue.o: Catalogue.cpp
	g++ -c Catalogue.cpp $(OPTIONS)

TrajetSimple.o: TrajetSimple.cpp
	g++ -c TrajetSimple.cpp $(OPTIONS)

TrajetCompose.o: TrajetCompose.cpp
	g++ -c TrajetCompose.cpp $(OPTIONS)

Trajet.o: Trajet.cpp
	g++ -c Trajet.cpp $(OPTIONS)

Noeud.o: Noeud.cpp
	g++ -c Noeud.cpp $(OPTIONS)

clean:
	rm -f *.o trajets