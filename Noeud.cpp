/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : Novembre 2025
    copyright            : (C) 2025 par Alban DAUDIN-CLAVAUD - Tristan DE FENOYL
    e-mail               : ---
*************************************************************************/

//---------- Réalisation de la classe <Noeud> (fichier Noeud.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Noeud.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
Trajet* Noeud::RenvoieTrajetCourant() const
// Algorithme :
//
{
    return trajet_courant;
} //----- Fin de RenvoieTrajetCourant

Noeud* Noeud::RenvoieNoeudApres() const
// Algorithme :
//
{
    return noeud_apres;
} //----- Fin de RenvoieNoeudApres

void Noeud::AjouterProchain(Noeud* nd_apres)
// Algorithme :
//
{
    noeud_apres = nd_apres;
} //----- Fin de AjouterProchain


//-------------------------------------------- Constructeurs - destructeur
Noeud::Noeud(Trajet *traj_courant)
    : trajet_courant(traj_courant), noeud_apres(nullptr)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Noeud>" << endl;
#endif
} //----- Fin de Noeud

Noeud::~Noeud()
// Algorithme :
// Supprime le trajet pointé par le noeud.
{
#ifdef MAP
    cout << "Appel au destructeur de <Noeud>" << endl;
#endif
    delete trajet_courant;
} //----- Fin de ~Noeud