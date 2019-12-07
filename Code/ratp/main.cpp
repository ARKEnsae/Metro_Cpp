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
    metro.ajouteTousStopTxt(project_directory);
    metro.getArret("2271").affiche();
    return 0;
}
