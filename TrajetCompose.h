/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : Novembre 2025
    copyright            : (C) 2025 par Alban DAUDIN-CLAVAUD - Tristan DE FENOYL
    e-mail               : ---
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Représente un voyage constitué d'une succession de trajets simples.
// Gère en interne la liste des escales et des modes de transport successifs.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher() const override;
    // Mode d'emploi :
    // Affiche le détail du trajet composé étape par étape.

    std::string RenvoieLigneFichier() const override;
    // Mode d'emploi :
    // Renvoie la ligne d'infos sur le trajet à écrire dans le csv

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose(const TrajetSimple** liste_trajets, int nb_trajets);
    // Mode d'emploi :
    // Construit un trajet composé à partir d'un tableau de pointeurs vers des
    // trajets simples valides. Copie les informations nécessaires (escales, modes).
    
    virtual ~TrajetCompose();
    // Mode d'emploi :
    // Libère la mémoire des tableaux internes (modes de transport et escales).

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    Trajet::MDT *mode_tr;
    char** escales;
    int nb_escales;
};

#endif // TRAJETCOMPOSE_H