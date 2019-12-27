#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "metro.h"
#include "itineraire.h"
#include <sstream> //Pour transformation
#include <windows.h> //couleurs palette

#include <string.h>
#include <stdio.h>
#include <sstream>
#include <algorithm> //??


#define INT_MAX 10000000
using namespace std;


//KIM à déplacer au bon endroit ? Demander à Alain
 bool trier_arrets_alphabet(Arret* arret1, Arret* arret2) {
        return (arret1->getNom() < arret2->getNom());
    }



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

    string project_directory = "W:/Documents/Cplusplus/Projet/ProjetC";//"W:/Bureau/ProjetCpp/ProjetC"
    Metro metro;
    metro.chargeDonnees(project_directory);


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




        cout<<endl<<" ----------------------- MENU -----------------------"<<endl<<endl;
        vector<Ligne*> lignes = metro.getLignes();



        vector<string> partie_menu;
        partie_menu.push_back("de depart");
        partie_menu.push_back("d'arrivee");
        vector<string> identifiants_depart_arrivee;

        for(int m=0; m < 2; m++){

        vector<Ligne*> lignes_entree;
        cout<<endl<<"Choisissez votre ligne " << partie_menu[m] <<" parmi les lignes suivantes : " << endl;
        cout<< "1, 2, 3, '3B', 4, 5, 6, 7, '7B', 8, 9, 10, 11, 12, 13 et 14" <<endl<<endl;
        string menu_ligne;
        cout<<"Ligne " << partie_menu[m] <<" : ";
        cin>>menu_ligne;
        cout<<endl;


        // Recuperation des arrêts de la ligne choisie
        for(int i=0; i < lignes.size(); ++i){
            if(lignes[i]->getNumero()==menu_ligne)
            {
            lignes_entree.push_back(lignes[i]);
            }
        }

        vector<string> arrets_entree_libelles;
        vector<Arret*> arrets_entree;
        for(int i=0; i < lignes_entree.size(); ++i){
                for(int j=0; j < lignes_entree[i]->getArrets().size(); ++j)
                {

                    if (std::find(arrets_entree_libelles.begin(), arrets_entree_libelles.end(), lignes_entree[i]->getArrets()[j]->getNom()) != arrets_entree_libelles.end())
                  {

                  }
                  else
                  {
                      arrets_entree_libelles.push_back(lignes_entree[i]->getArrets()[j]->getNom());
                      arrets_entree.push_back(lignes_entree[i]->getArrets()[j]);
                  }
                }
        }
        sort(arrets_entree_libelles.begin(),arrets_entree_libelles.end());
        sort(arrets_entree.begin(),arrets_entree.end(),trier_arrets_alphabet);

        // Choix de l'arrêt
        cout<<endl<<endl<<"Choisissez votre arret " << partie_menu[m] <<" : " << endl << endl;
        for (int i = 0; i < arrets_entree_libelles.size(); ++i)
        {
            cout<< i << " : " << arrets_entree[i]->getNom()<<endl;
        }
        cout<<endl<<endl<<"Arret " << partie_menu[m]<< " : ";
        int menu_arret_depart;
        cin>>menu_arret_depart;
        cout<<"("<< arrets_entree[menu_arret_depart]->getNom() <<")";
        cout<<endl;
        stringstream ss;
        ss << arrets_entree[menu_arret_depart]->getId();
        string str = ss.str();
        identifiants_depart_arrivee.push_back(str);
        }



    cout<< endl << endl;
    //cout << "Depart : " << metro.getArret(identifiants_depart_arrivee[0])->getNom()<<endl;
    //cout <<  "Arrivee : " << metro.getArret(identifiants_depart_arrivee[1])->getNom()<<endl;
    metro.itineraire->DijkstrasFinal(identifiants_depart_arrivee[0],identifiants_depart_arrivee[1]);

    return 0;
}
