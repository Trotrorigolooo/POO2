/*************************************************************************
                           Main  -  Application de Voyage
                             -------------------
    début                : Novembre 2025
    copyright            : (C) 2025 par Alban DAUDIN-CLAVAUD - Tristan DE FENOYL
    e-mail               : ---
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Trajet.h"
#include "Noeud.h"
#include "Catalogue.h"

//---------------------------------------------------------------- Fonctions

static void AfficheMenu(){
    cout << "****MENU****"<<endl;
    cout << "Tapez : "<<endl;
    cout << "0 si vous souhaitez consulter le catalogue"<<endl;
    cout << "1 si vous souhaitez rechercher uniquement un trajet sur notre catalogue qui va d'une ville A vers une ville B"<<endl;
    cout << "2 si vous souhaitez rechercher un ou plusieurs trajets qui vous permettent d'aller d'une ville A vers une ville B (recherche complexe)"<<endl;
    cout << "3 si vous souhaitez ajouter un trajet simple (ville A, ville B et mode de transport)"<<endl;
    cout << "4 si vous souhaitez ajouter un trajet composé (strictement plus de 2 villes)"<<endl;
    cout << "5 si vous souhaitez nous quitter :("<<endl;
    cout << "6 si vous souhaitez sauvergarder votre catalogue dans un fichier"<<endl;
    cout << "7 si vous souhaitez charger des trajets depuis un fichier"<<endl;
    cout << "****FIN DU MENU****"<<endl;
    cout << "Votre choix :"<<endl;
    return;
}

//---------------------------------------------------------------- Main
int main(){

    Catalogue catalogue;
    cout << "Bienvenue sur notre application qui vous permettra de voyager de partout !"<<endl;
    cout << "Appuyez sur Entrée pour continuer..."<<endl;
    cin.get();
    AfficheMenu();
    int choix;

    while (true){
        if (cin>>choix){
            cin.ignore(100, '\n');

            if (choix == 5){
                break;
            }

            switch (choix){
                case 0:{
                    catalogue.Afficher();
                    break;
                }
                case 1:{
                    char depart[100];
                    cout << "Entrez la ville de départ : ";
                    cin.getline(depart, 100);
                    char arrivee[100];
                    cout << "Entrez la ville d'arrivée : ";
                    cin.getline(arrivee, 100);
                    cout << "***Résultat de la recherche***"<<endl;
                    catalogue.RechercheSimpleTrajet(depart, arrivee);
                    cout<<"***Fin de la recherche simple***"<<endl;
                    break;
                }
                case 2:{
                    char depart[100];
                    cout << "Entrez la ville de départ : ";
                    cin.getline(depart, 100);
                    char arrivee[100];
                    cout << "Entrez la ville d'arrivée : ";
                    cin.getline(arrivee, 100);
                    cout << "***Résultat de la recherche***"<<endl;
                    catalogue.RechercheComposeTrajet(depart, arrivee);
                    cout<<"***Fin de la recherche composée***"<<endl;
                    break;
                }
                case 3:{
                    char depart[100];
                    cout << "Entrez la ville de départ : ";
                    cin.getline(depart, 100);
                    char arrivee[100];
                    cout << "Entrez la ville d'arrivée : ";
                    cin.getline(arrivee, 100);
                    int choix_mdt;
                    cout << "Choisir le mode de transport via son numéro : 1. Avion ; 2. Bateau ; 3. Voiture ; 4. Train : ";
                    cin >> choix_mdt;
                    cin.ignore(100,'\n');
                    Trajet::MDT mdt = (Trajet::MDT)(choix_mdt - 1);
                    TrajetSimple* trajet = new TrajetSimple(depart, arrivee, mdt);
                    catalogue.AjouterTrajet(trajet);
                    cout << "Votre trajet :"<<endl;
                    trajet->Afficher();
                    cout << "A été ajouté avec succès !"<<endl;
                    break;
                }
                case 4:{
                    int nb_trajets;
                    cout << "Entrez le nombre de trajets simples que va contenir votre trajet composé : ";
                    cin >> nb_trajets;
                    cin.ignore(100, '\n');
                    TrajetSimple **trajets = new TrajetSimple*[nb_trajets];
                    int i;
                    for (i = 0; i<nb_trajets; i++){
                        char depart[100];
                        char arrivee[100];

                        cout << "**Étape " << i + 1 << " sur " << nb_trajets << "**" << endl;

                        // --- LOGIQUE DE CONTINUITÉ ---
                        if (i == 0) {
                            // Premier trajet : L'utilisateur choisit librement
                            cout << "Entrez la ville de départ : ";
                            cin.getline(depart, 100);
                        } else {
                            // Trajets suivants : Le départ est FORCÉ (Arrivée du précédent)
                            // On copie la chaîne de caractères de l'arrivée précédente vers 'depart'
                            strcpy(depart, trajets[i-1]->RenvoieArrivee());
                            cout << "Ville de départ (automatique) : " << depart << endl;
                        }

                        // --- SUITE DE LA SAISIE ---
                        cout << "Entrez la ville d'arrivée : ";
                        cin.getline(arrivee, 100);

                        // Lecture du mode de transport
                        int choix_mdt; // On lit un int, pas un Enum directement
                        cout << "Choisir le mode de transport : 1. Avion ; 2. Bateau ; 3. Voiture ; 4. Train : ";
                        cin >> choix_mdt;
                        
                        // Nettoyage buffer après un int
                        cin.ignore(100, '\n');

                        Trajet::MDT mdt = (Trajet::MDT)(choix_mdt - 1);
                        
                        trajets[i] = new TrajetSimple(depart, arrivee, mdt);
                    }
                    TrajetCompose* tc = new TrajetCompose((const TrajetSimple**)trajets, nb_trajets);
                    catalogue.AjouterTrajet(tc);
                    cout << "Votre trajet :"<<endl;
                    tc->Afficher();
                    cout << "A été ajouté avec succès !"<<endl;
                    for(int i = 0; i < nb_trajets; i++) {
                        delete trajets[i]; // On détruit les objets TrajetSimple temporaires
                    }
                    delete[] trajets;
                    break;
                }

                case 6:{
                    char nomfichier[100];
                    cout << "Entrer le nom du fichier dans lequel vous voulez écrire : ";
                    cin.getline(nomfichier, 100);
                    catalogue.Sauvegarder(nomfichier);
                    break;
                }

                case 7:{
                    char nomfichier[100];
                    cout << "Entrer le nom du fichier à ouvrir : ";
                    cin.getline(nomfichier, 100);
                    catalogue.Charger(nomfichier); 
                    break;
                }

            default:
                cout<<"Sélection non reconnue, merci de réessayer"<<endl;
            
            }
        }
        else {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Veuillez entrer un nombre ! "<< endl;
        }
        cout << "Entrée pour afficher le menu : ";
        cin.get();
        AfficheMenu();
    }
    cout<<"Au revoir !";
    return 0;
}