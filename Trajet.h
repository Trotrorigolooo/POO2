/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : Novembre 2025
    copyright            : (C) 2025 par Alban DAUDIN-CLAVAUD - Tristan DE FENOYL
    e-mail               : ---
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Classe abstraite définissant la structure de base d'un trajet (départ,
// arrivée) et l'interface commune pour les trajets simples et composés.
//------------------------------------------------------------------------

class Trajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    enum MDT{
        AVION,
        BATEAU,
        VOITURE,
        TRAIN
    };

    static const char* Mtos(const MDT mdt);
    // Mode d'emploi :
    // Méthode statique utilitaire pour convertir une valeur de l'énumération
    // MDT (Mode de Transport) en chaîne de caractères lisible.
    // Contrat :
    // Retourne "Inconnu" si le mode n'est pas reconnu.

    const char* RenvoieDepart() const;
    // Mode d'emploi :
    // Accesseur pour obtenir la ville de départ.
    
    const char* RenvoieArrivee() const;
    // Mode d'emploi :
    // Accesseur pour obtenir la ville d'arrivée.

    bool VerifTrajet(const char* dep, const char* arr) const;
    // Mode d'emploi :
    // Vérifie si le trajet courant correspond exactement aux villes de
    // départ et d'arrivée passées en paramètre.
    
    virtual void Afficher() const = 0;
    // Mode d'emploi :
    // Méthode virtuelle pure pour afficher les détails du trajet.
    // Doit être implémentée par les classes filles.

//-------------------------------------------- Constructeurs - destructeur
    Trajet(const char* dep, const char* arr);
    // Mode d'emploi :
    // Constructeur protégé (car classe abstraite) qui initialise les
    // villes de départ et d'arrivée en allouant la mémoire nécessaire.

    virtual ~Trajet();
    // Mode d'emploi :
    // Destructeur virtuel pour désallouer la mémoire des chaînes de caractères.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    char* depart;
    char* arrivee;
};

#endif // TRAJET_H