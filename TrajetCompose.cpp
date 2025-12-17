/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : Novembre 2025
    copyright            : (C) 2025 par Alban DAUDIN-CLAVAUD - Tristan DE FENOYL
    e-mail               : ---
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher() const
// Algorithme :
// Parcourt les tableaux d'escales et de modes pour afficher la suite de trajets.
{
    int i;
    cout << "De " << depart << " à " << escales[0] << " en " << Trajet::Mtos(mode_tr[0]) << " - ";
    for(i=0;i<nb_escales-1;i++){
        cout << "De " << escales[i] << " à " << escales[i+1] << " en " << Trajet::Mtos(mode_tr[i+1]) << " - ";
    }
    cout << "De " << escales[i] << " à " << arrivee << " en " << Trajet::Mtos(mode_tr[i+1]) << "\n";
} //----- Fin de Afficher

std::string TrajetCompose::RenvoieLigneFichier() const
// Algorithme :
// Aucun
{
    std::string ligne_renvoie;
    ligne_renvoie = std::string("1")+std::string(",")+std::to_string(nb_escales)+std::string(",")+depart+std::string(",")+Mtos(mode_tr[0])+std::string(",");
    int i;
    for(i=0;i<nb_escales;i++){
        ligne_renvoie += escales[i]+std::string(",")+Mtos(mode_tr[i+1])+std::string(",");
    }
    ligne_renvoie+=arrivee+std::string(",");
    return ligne_renvoie;
}


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(const TrajetSimple** liste_trajets, int nb_trajets)
    : Trajet(liste_trajets[0]->RenvoieDepart(), liste_trajets[nb_trajets-1]->RenvoieArrivee()),
      nb_escales(nb_trajets - 1) 
// Algorithme :
// Initialise le parent Trajet avec le départ global et l'arrivée globale.
// Alloue et remplit les tableaux d'escales et de modes de transport à partir
// de la liste des trajets simples fournis.
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    // 1. Allocation des tableaux internes
    mode_tr = new Trajet::MDT[nb_trajets]; 
    
    if (nb_escales > 0) {
        escales = new char*[nb_escales];
    } else {
        escales = nullptr; 
    }

    // 2. Extraction et Copie des données
    for (int i = 0; i < nb_trajets; i++) {
        mode_tr[i] = liste_trajets[i]->RenvoieMDT();

        if (i < nb_trajets - 1) {
            const char* ville_etape = liste_trajets[i]->RenvoieArrivee();
            escales[i] = new char[strlen(ville_etape) + 1];
            strcpy(escales[i], ville_etape);
        }
    }
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose()
// Algorithme :
// Désalloue les tableaux dynamiques internes.
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    delete[] mode_tr;
    int i;
    for(i=0;i<nb_escales;i++){
        delete[] escales[i];
    }
    delete[] escales;
} //----- Fin de ~TrajetCompose