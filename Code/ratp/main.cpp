#include <iostream>
#include <vector>
#include "metro.h"
#include "IHM.h"


using namespace std;


int main()
{
    IHM menu;

    //string project_directory = "W:/Documents/Cplusplus/Projet/ProjetC";
    string project_directory = "W:/Bureau/ProjetCpp/ProjetC";
    Metro metro;
    metro.chargeDonnees(project_directory);
    vector<string> identifiants_depart_arrivee = menu.choixItineraire(metro);
    bool min_itineraire = menu.choixTypeItineraire();
    //cout << "Depart : " << metro.getArret(identifiants_depart_arrivee[0])->getNom() << identifiants_depart_arrivee[0]<<endl;
    //cout <<  "Arrivee : " << metro.getArret(identifiants_depart_arrivee[1])->getNom()<< identifiants_depart_arrivee[1] << endl;

    metro.itineraire->DijkstrasFinal(identifiants_depart_arrivee[0],identifiants_depart_arrivee[1], min_itineraire);
    while(menu.quitter()){
        metro.majNodes(project_directory);
        identifiants_depart_arrivee = menu.choixItineraire(metro);
        min_itineraire = menu.choixTypeItineraire();
        metro.itineraire->DijkstrasFinal(identifiants_depart_arrivee[0],identifiants_depart_arrivee[1], min_itineraire);
    }

    return 0;
}
