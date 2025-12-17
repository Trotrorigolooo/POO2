/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : Novembre 2025
    copyright            : (C) 2025 par Alban DAUDIN-CLAVAUD - Tristan DE FENOYL
    e-mail               : ---
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char* Trajet::Mtos(Trajet::MDT mdt)
// Algorithme :
// Utilise un switch pour retourner la chaîne correspondante.
{
    switch (mdt){
        case 0 : return "Avion";
        case 1 : return "Bateau";
        case 2 : return "Voiture";
        case 3 : return "Train";
        default: return "Inconnu";
    }
} //----- Fin de mtos

bool Trajet::VerifTrajet(const char* dep, const char* arr) const 
// Algorithme :
// Compare les chaînes avec strcmp.
{
    if(strcmp(dep,depart) || strcmp(arr,arrivee)) return false;
    return true;
} //----- Fin de VerifTrajet

const char *Trajet::RenvoieDepart() const
// Algorithme :
// Aucun
{
    return depart;
} //----- Fin de RenvoieDepart

const char *Trajet::RenvoieArrivee() const
// Algorithme :
// Aucun
{
    return arrivee;
} //----- Fin de RenvoieArrivee


//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet(const char* dep, const char* arr)
// Algorithme :
// Alloue dynamiquement la mémoire pour les chaînes depart et arrivee
// et effectue une copie profonde (strcpy).
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
    depart = new char[strlen(dep)+1];
    strcpy(depart,dep);
    arrivee = new char[strlen(arr)+1];
    strcpy(arrivee,arr);
} //----- Fin de Trajet

Trajet::~Trajet()
// Algorithme :
// Libère la mémoire allouée pour les attributs.
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
    delete [] depart;
    delete [] arrivee;
} //----- Fin de ~Trajet