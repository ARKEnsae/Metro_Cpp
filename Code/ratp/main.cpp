#include <iostream>
#include <vector>
#include "metro.h"
#include "IHM.h"


#define INT_MAX 10000000
using namespace std;


int main()
{

    IHM menu;

    //string project_directory = "W:/Documents/Cplusplus/Projet/ProjetC";
    string project_directory = "W:/Bureau/ProjetCpp/ProjetC";
    //"W:/Bureau/ProjetCpp/ProjetC"
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
    //metro.itineraire->DijkstrasFinal("2539","2075");

    // Alain

    //metro.getArret("2271").affiche();

    /*cout << metro.getArret("2035")->getLigne()[1]->getNom()<<endl;
    cout << metro.getArret("2067")->getLigne()[0]->getNom()<<endl;

    cout << "arret : " << metro.getArret("2271")->getNom() <<
     " ligne : "<< metro.getArret("2271")->getLigne()[0]->getNumero()<< " " <<
     metro.getArret("2271")->getLigne()[0]->getNom();*/
     //cout << "arret : " << metro.getArret("2271")->getNom() <<
     //" ligne : "<< metro.getArret("2271")->getLigne()[1]->getNumero()<< " " <<
     //metro.getArret("2271")->getLigne()[1]->getNom();





    return 0;
}
