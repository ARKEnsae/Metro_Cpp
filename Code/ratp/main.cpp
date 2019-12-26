#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "metro.h"
#include "itineraire.h"
#include <sstream> //Pour transformation


#include <string.h>
#include <stdio.h>
#include <sstream>
#include <algorithm> //??


#define INT_MAX 10000000

using namespace std;



int main()
{

    //Kim
/*charger_nodes("W:/Documents/Cplusplus/Projet/ProjetC/Data projet/voisins.txt");
charger_edges("W:/Documents/Cplusplus/Projet/ProjetC/Data projet/voisins.txt");*/
    string project_directory = "W:/Bureau/ProjetCpp/ProjetC";//"W:/Documents/Cplusplus/Projet/ProjetC";
    Metro metro;
    metro.chargeDonnees(project_directory);
    //Itineraire itineraire;
    //itineraire.chargerDonnees(project_directory);
    metro.itineraire->DijkstrasFinal("1804","1948");

// Faire les trois étapes sinon on écrase mal ce qui est fait avant...

    // Alain

    //metro.getArret("2271").affiche();

    cout << metro.getArret("2035")->getLigne()[1]->getNom()<<endl;
    cout << metro.getArret("2067")->getLigne()[0]->getNom()<<endl;

    cout << "arret : " << metro.getArret("2271")->getNom() <<
     " ligne : "<< metro.getArret("2271")->getLigne()[0]->getNumero()<< " " <<
     metro.getArret("2271")->getLigne()[0]->getNom();
     //cout << "arret : " << metro.getArret("2271")->getNom() <<
     //" ligne : "<< metro.getArret("2271")->getLigne()[1]->getNumero()<< " " <<
     //metro.getArret("2271")->getLigne()[1]->getNom();
    return 0;
}
