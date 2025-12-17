/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : Novembre 2025
    copyright            : (C) 2025 par Alban DAUDIN-CLAVAUD - Tristan DE FENOYL
    e-mail               : ---
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher() const
// Algorithme :
//
{
    cout << "De " << depart << " à " << arrivee << " en " << Trajet::Mtos(mode_tr) << "\n";
} //----- Fin de Afficher

Trajet::MDT TrajetSimple::RenvoieMDT() const 
// Algorithme :
//
{
    return mode_tr;
} //----- Fin de RenvoieMDT

std::string TrajetSimple::RenvoieLigneFichier() const
// Algorithme :
// Aucun
{
    std::string ligne_renvoie;
    ligne_renvoie = std::string("0")+depart+std::string(",")+arrivee+std::string(",")+Mtos(mode_tr);
    return ligne_renvoie;
}


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const char* dep, const char* arr, Trajet::MDT mdt)
    : Trajet(dep,arr), mode_tr(mdt)
// Algorithme :
// Appelle le constructeur de Trajet et initialise le mode de transport.
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple