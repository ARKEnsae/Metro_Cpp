#include <iostream>
#include <string>
#include <vector>
#include "metro.h"
#include <windows.h> //couleurs palette


#define INT_MAX 10000000
using namespace std;


int main()
{

    //system("chcp 1252");

  HANDLE  hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  //https://docs.microsoft.com/en-us/windows/console/console-screen-buffers#span-idwin32characterattributesspanspan-idwin32characterattributesspancharacter-attributes
  //for(int k=0;k<100;k++){
         SetConsoleTextAttribute(hConsole, 14); //blanc = 15 // jaune = 14
      //   cout << "hey" << endl;
  //}

    //string project_directory = "W:/Documents/Cplusplus/Projet/ProjetC";
    string project_directory = "W:/Bureau/ProjetCpp/ProjetC";
    //"W:/Bureau/ProjetCpp/ProjetC"
    Metro metro;
    metro.chargeDonnees(project_directory);
    vector<string> identifiants_depart_arrivee = metro.menu();
    cout << "Depart : " << metro.getArret(identifiants_depart_arrivee[0])->getNom() << identifiants_depart_arrivee[0]<<endl;
    cout <<  "Arrivee : " << metro.getArret(identifiants_depart_arrivee[1])->getNom()<< identifiants_depart_arrivee[1] << endl;

    metro.itineraire->DijkstrasFinal(identifiants_depart_arrivee[0],identifiants_depart_arrivee[1], false);
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
