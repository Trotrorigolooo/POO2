/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : Novembre 2025
    copyright            : (C) 2025 par Alban DAUDIN-CLAVAUD - Tristan DE FENOYL
    e-mail               : ---
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::AjouterTrajet(Trajet* trajet)
// Algorithme :
// Crée un nouveau Noeud et l'ajoute à la fin de la liste chaînée.
// Met à jour les pointeurs Liste et Dernier.
{
    Noeud *nouveau_noeud = new Noeud(trajet);
    if(Liste == nullptr){
        Liste = nouveau_noeud; 
        Dernier = nouveau_noeud; 
        return;
    }
    Dernier->AjouterProchain(nouveau_noeud); 
    Dernier = nouveau_noeud;
    return;
} //----- Fin de AjouterTrajet

void Catalogue::Afficher() const
// Algorithme :
// Parcourt la liste chaînée du début à la fin en appelant Afficher() sur chaque trajet.
{
    Noeud* noeud_act = Liste;
    cout << "**Affichage Catalogue**" << endl;
    while(noeud_act!=nullptr){
        noeud_act->RenvoieTrajetCourant()->Afficher();
        noeud_act = noeud_act->RenvoieNoeudApres();
    }
    cout << "**Fin Affichage Catalogue**" << endl;
} //----- Fin de Afficher

void Catalogue::RechercheSimpleTrajet(const char* depart, const char* arrivee) const
// Algorithme :
// Parcourt la liste pour trouver les trajets dont départ et arrivée correspondent exactement.
{
    Noeud* noeud_act = Liste;
    int trouve = 0;
    while(noeud_act!=nullptr){
        if(noeud_act->RenvoieTrajetCourant()->VerifTrajet(depart,arrivee)){
            noeud_act->RenvoieTrajetCourant()->Afficher();
            trouve = 1;
        }
        noeud_act = noeud_act->RenvoieNoeudApres();
    }
    if (!trouve){
        cout << "Aucun trajet correspondant"<< endl;
    }
    return;
} //----- Fin de RechercheSimpleTrajet

void Catalogue::RechercheComposeTrajet(const char* depart, const char* arrivee) const 
// Algorithme :
// Initialise les structures nécessaires (buffer) et lance la recherche récursive.
{
    const Trajet* buffer[100]; // Ce tableau vit tant que cette fonction n'est pas finie
    bool trouve = false;
    RechercheComposeTrajetRec(depart, arrivee, buffer, 0, trouve);
    if (!trouve){
        cout<<"Aucun trajet correspondant"<<endl;
    }
} //----- Fin de RechercheComposeTrajet


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue()
    : Liste(nullptr), Dernier(nullptr)
// Algorithme :
// Initialise les pointeurs de liste à NULL.
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue

Catalogue::~Catalogue()
// Algorithme :
// Parcourt la liste et supprime chaque Noeud.
// (Le destructeur de Noeud se charge de supprimer le Trajet).
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    Noeud* noeud_act = Liste;
    while(noeud_act!=nullptr){
        Noeud* noeud_apres = noeud_act->RenvoieNoeudApres();
        delete noeud_act;
        noeud_act = noeud_apres;
    }
} //----- Fin de ~Catalogue

void Catalogue::Sauvegarder(std::string nomfichier)
// Algorithme :
// Parcourt la liste et supprime chaque Noeud.
// (Le destructeur de Noeud se charge de supprimer le Trajet).
{
    std::ofstream fichier;
    fichier.open(nomfichier);
    Noeud* noeud_act = Liste;
    while(noeud_act!=nullptr){
        fichier << noeud_act->RenvoieTrajetCourant()->RenvoieLigneFichier()<<endl;
        noeud_act = noeud_act->RenvoieNoeudApres();
    }
    fichier.close();
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Catalogue::RechercheComposeTrajetRec(const char* depart, const char* arrivee, const Trajet* trajets_deja_faits[100], int nb_tdf, bool &trouve) const
// Algorithme :
// Parcours en profondeur (DFS).
// - Si destination atteinte : affichage et return.
// - Sinon, parcourt le catalogue pour trouver des continuations possibles.
// - Vérifie l'absence de cycles avant d'ajouter une étape et de faire l'appel récursif.
{
    if (strcmp(depart,arrivee)==0){
        trouve = true;
        cout << "**Solution possible**"<<endl;
        for (int i = 0; i < nb_tdf; i++){
            trajets_deja_faits[i]->Afficher();
        }
        cout << "**Fin solution**"<<endl;
        return;
    }

    Noeud* noeud_act = Liste;

    while(noeud_act!=nullptr){ 
        const char* depart_act = noeud_act->RenvoieTrajetCourant()->RenvoieDepart();
        if (strcmp(depart, depart_act)==0){
            bool deja_fait = false;
            for (int i = 0; i < nb_tdf; i++){
                if (trajets_deja_faits[i] == noeud_act->RenvoieTrajetCourant()){
                    deja_fait = true;
                }
            }
            if (deja_fait == false){
                trajets_deja_faits[nb_tdf] = noeud_act->RenvoieTrajetCourant();
                RechercheComposeTrajetRec(noeud_act->RenvoieTrajetCourant()->RenvoieArrivee(), arrivee, trajets_deja_faits, nb_tdf+1, trouve);
            }

        }
        noeud_act = noeud_act->RenvoieNoeudApres();
    }
    return;
} //----- Fin de RechercheComposeTrajetRec