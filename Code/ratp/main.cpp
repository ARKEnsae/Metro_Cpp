#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Arret.h"
#include "metro.h"
#include <sstream> //Pour transformation

using namespace std;

int nombre_lignes(const char* chemin){
    ifstream file(chemin);
    int nb_lignes = 0;
    string line;
    while (getline(file, line))
	{
		nb_lignes++;
	}
  file.close();
    return(nb_lignes);
}
int main()
{
    Metro metro;
    string project_directory = "W:/Bureau/ProjetCpp/ProjetC";
    metro.chargeDonnees(project_directory);
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
