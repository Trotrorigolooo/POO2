/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : Novembre 2025
    copyright            : (C) 2025 par Alban DAUDIN-CLAVAUD - Tristan DE FENOYL
    e-mail               : ---
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Représente un trajet direct entre deux villes via un mode de transport spécifique.
// Hérite de la classe Trajet.
//------------------------------------------------------------------------

class TrajetSimple : public Trajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher() const override;
    // Mode d'emploi :
    // Affiche le départ, l'arrivée et le mode de transport.

    Trajet::MDT RenvoieMDT() const;
    // Mode d'emploi :
    // Retourne le mode de transport de ce trajet.

    string RenvoieLigneFichier() const override;
    // Mode d'emploi :
    // Renvoie la ligne d'infos sur le trajet à écrire dans le csv

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple(const char* dep, const char* arr, Trajet::MDT mdt);
    // Mode d'emploi :
    // Construit un trajet simple avec ville départ, arrivée et moyen de transport.

    ~TrajetSimple();
    // Mode d'emploi :
    // Destructeur de TrajetSimple.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    MDT mode_tr;
};

#endif // TRAJETSIMPLE_H