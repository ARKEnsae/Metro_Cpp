#include <iostream>
#include <vector>
#include "metro.h"
#include "IHM.h"
#include "Graphe.h"

using namespace std;


int main()
{
    //string project_directory = "W:/Documents/Cplusplus/Projet/ProjetC";
    string project_directory = "W:/Bureau/ProjetCpp/ProjetC";
    bool activerCouleur = false;

    IHM menu(activerCouleur);
    Metro metro;
    metro.chargeDonnees(project_directory);
    Graphe graphe(project_directory);
    vector<string> identifiants_depart_arrivee = menu.choixItineraire(metro);
    bool min_itineraire = menu.choixTypeItineraire();

    Itineraire itineraire_sortie(graphe.dijkstras(identifiants_depart_arrivee[0],
                                                  identifiants_depart_arrivee[1],
                                                  min_itineraire),
                                 metro);
    menu.AfficherItineraire(itineraire_sortie);


    while(menu.quitter()){
        graphe.reinitialiseNodes();
        identifiants_depart_arrivee = menu.choixItineraire(metro);
        min_itineraire = menu.choixTypeItineraire();
        Itineraire itineraire_sortie(graphe.dijkstras(identifiants_depart_arrivee[0],
                                                      identifiants_depart_arrivee[1],
                                                      min_itineraire),
                                     metro);

        menu.AfficherItineraire(itineraire_sortie);
    }

    return 0;
}
