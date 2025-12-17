/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : Novembre 2025
    copyright            : (C) 2025 par Alban DAUDIN-CLAVAUD - Tristan DE FENOYL
    e-mail               : ---
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Noeud.h"
#include <string>

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Gère une collection de trajets à l'aide d'une liste chaînée.
// Permet d'ajouter des trajets, de les afficher et d'effectuer des recherches
// (simples ou avancées/combinées).
//------------------------------------------------------------------------

class Catalogue 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterTrajet(Trajet* trajet);
    // Mode d'emploi :
    // Ajoute un nouveau trajet à la fin du catalogue.
    // Contrat :
    // Le catalogue devient propriétaire du pointeur trajet.

    void Afficher() const;
    // Mode d'emploi :
    // Affiche le contenu complet du catalogue.

    void RechercheSimpleTrajet(const char* depart, const char* arrivee) const;
    // Mode d'emploi :
    // Recherche et affiche les trajets directs correspondant au départ et à l'arrivée.

    void RechercheComposeTrajet(const char* depart, const char* arrivee) const;
    // Mode d'emploi :
    // Recherche avancée (implique la méthode récursive) pour trouver des
    // combinaisons de trajets.

    void Sauvegarder(std::string nomfichier);
    // Mode d'emploi :
    // Sauvegarde dans le fichier

    void Charger(std::string nomfichier);
    // Mode d'emploi :
    // Charge un fichier existant

//-------------------------------------------- Constructeurs - destructeur
    Catalogue();
    // Mode d'emploi :
    // Construit un catalogue vide.

    virtual ~Catalogue();
    // Mode d'emploi :
    // Détruit le catalogue et tous les trajets qu'il contient.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    void RechercheComposeTrajetRec(const char* depart, const char* arrivee, const Trajet* trajets_deja_faits[100], int nb_tdf, bool &trouve) const;
    // Mode d'emploi :
    // Méthode interne récursive pour la recherche de parcours (DFS).
    // Evite les cycles en vérifiant les villes déjà visitées.

//----------------------------------------------------- Attributs protégés
    Noeud* Liste;   // Pointeur de tête de liste
    Noeud* Dernier; // Pointeur de fin de liste (optimisation ajout)
};

#endif // CATALOGUE_H