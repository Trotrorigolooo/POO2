/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : Novembre 2025
    copyright            : (C) 2025 par Alban DAUDIN-CLAVAUD - Tristan DE FENOYL
    e-mail               : ---
*************************************************************************/

//---------- Interface de la classe <Noeud> (fichier Noeud.h) ----------------
#if ! defined ( NOEUD_H )
#define NOEUD_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <Noeud>
// Élément de base de la liste chaînée utilisée par le Catalogue.
// Contient un pointeur vers un Trajet et un pointeur vers le Noeud suivant.
//------------------------------------------------------------------------

class Noeud 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Trajet *RenvoieTrajetCourant() const;
    // Mode d'emploi :
    // Retourne le pointeur vers le trajet stocké dans ce noeud.

    Noeud *RenvoieNoeudApres() const;
    // Mode d'emploi :
    // Retourne le pointeur vers le noeud suivant dans la liste.

    void AjouterProchain(Noeud *nd_apres);
    // Mode d'emploi :
    // Définit le noeud suivant.

//-------------------------------------------- Constructeurs - destructeur
    Noeud(Trajet *traj_courant);
    // Mode d'emploi :
    // Construit un noeud contenant le trajet donné. Le suivant est initialisé à NULL.

    ~Noeud();
    // Mode d'emploi :
    // Destructeur qui supprime le Trajet associé.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    Trajet *trajet_courant;
    Noeud *noeud_apres;
};

#endif // NOEUD_H