#include "IHM.h"
#include <iostream>
#include <string>
#include <vector>
#include <vector>
#include <algorithm>
#include <sstream>
#include <limits>


#include "metro.h"
#include "ligne.h"
#include "Arret.h"
#include <windows.h> //couleurs palette


using namespace std;

IHM::IHM()
{
        //system("chcp 1252");
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  //https://docs.microsoft.com/en-us/windows/console/console-screen-buffers#span-idwin32characterattributesspanspan-idwin32characterattributesspancharacter-attributes
  //for(int k=0;k<100;k++){
    SetConsoleTextAttribute(hConsole, 14); //blanc = 15 // jaune = 14
      //   cout << "hey" << endl;
  //}
}

IHM::~IHM()
{
    //dtor
}


bool trier_arrets_alphabet(Arret* arret1, Arret* arret2) {
    return (arret1->getNom() < arret2->getNom());
}
bool is_not_digit(char c)
{
    return !std::isdigit(c);
}

bool numeric_string_compare(const std::string& s1, const std::string& s2)
{
    // handle empty strings...

    std::string::const_iterator it1 = s1.begin(), it2 = s2.begin();

    if (std::isdigit(s1[0]) && std::isdigit(s2[0])) {
        int n1, n2;
        std::stringstream ss(s1);
        ss >> n1;
        ss.clear();
        ss.str(s2);
        ss >> n2;

        if (n1 != n2) return n1 < n2;

        it1 = std::find_if(s1.begin(), s1.end(), is_not_digit);
        it2 = std::find_if(s2.begin(), s2.end(), is_not_digit);
    }

    return std::lexicographical_compare(it1, s1.end(), it2, s2.end());
}

vector<string> IHM::choixItineraire(Metro metro)
{

    cout<<endl<<" ----------------------- MENU -----------------------"<<endl<<endl;

    vector<string> partie_menu;
    partie_menu.push_back("de depart");
    partie_menu.push_back("d'arrivee");
    vector<string> identifiants_depart_arrivee;

    vector<string> id_ligne;
    vector<Ligne*> liste_lignes = metro.getLignes();
    for(int i = 0; i < liste_lignes.size(); ++i){
        id_ligne.push_back(liste_lignes[i]->getNumero());
    }
    std::vector<string>::iterator it = std::unique (id_ligne.begin(), id_ligne.end());                                                          //                ^
    id_ligne.resize(std::distance(id_ligne.begin(),it) );



    for(int m = 0; m < 2; m++)
    {
        vector<Ligne*> lignes_entree;
        cout<<endl<<"Choisissez votre ligne " << partie_menu[m] <<" parmi les lignes suivantes : " << endl;
        cout << id_ligne[0];
        for(int i = 1; i < (id_ligne.size()-1); ++i){
            cout << ", " << id_ligne[i];
        }
        cout << " et " << id_ligne[id_ligne.size()-1] << endl;

        string menu_ligne;
        cout<<"Ligne " << partie_menu[m] <<" : ";
        cin>>menu_ligne;
        while ( find(id_ligne.begin(), id_ligne.end(), menu_ligne) == id_ligne.end() ){
            cout << "Choix incorrect, veuillez essayer de nouveau :" << endl;
            cin>>menu_ligne;
        }

        cout<<endl;

        // Recuperation des arrêts de la ligne choisie
        for(int i=0; i < liste_lignes.size(); ++i)
        {
            if(liste_lignes[i]->getNumero()==menu_ligne)
            {
                lignes_entree.push_back(liste_lignes[i]);
            }
        }

        vector<string> arrets_entree_libelles;
        vector<Arret*> arrets_entree;
        for(int i=0; i < lignes_entree.size(); ++i)
        {
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
        while(cin.fail()){ //pour eviter bug si on entre une chqine de caracteres
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Choix incorrect, veuillez essayer de nouveau :" << endl;
            cin>>menu_arret_depart;
        }

        while(!(menu_arret_depart >=0 & menu_arret_depart <  arrets_entree_libelles.size())){
            cout << "Choix incorrect, veuillez essayer de nouveau :" << endl;
            cin>>menu_arret_depart;
        }

        cout<<"("<< arrets_entree[menu_arret_depart]->getNom() <<")";
        cout<<endl;
        stringstream ss;
        ss << arrets_entree[menu_arret_depart]->getId();
        string str = ss.str();
        identifiants_depart_arrivee.push_back(str);
    }

    cout<< endl << endl;
    return(identifiants_depart_arrivee);
}

bool IHM::choixTypeItineraire(){
        string menu_ligne;
        cout<<"Voulez-vous l'itineraire : " << endl <<
        " 0 : Le plus rapide ?" << endl <<
        " 1 : Avec le moins de changements ?" <<endl;
        vector<string> choix_possibles;
        choix_possibles.push_back("0");
        choix_possibles.push_back("1");
        cin>>menu_ligne;
        while (find(choix_possibles.begin(), choix_possibles.end(), menu_ligne) == choix_possibles.end() ){
            cout << "Choix incorrect, veuillez essayer de nouveau :" << endl;
            cin>>menu_ligne;
        }
        cout << endl  << endl;
        return(menu_ligne == "1");
}

bool IHM::quitter(){
        string menu_ligne;
        cout<< endl << endl << "Voulez-vous : " << endl <<
        " 0 : Quitter l'application ?" << endl <<
        " 1 : Chercher un nouvel itineraire ?" <<endl;
        vector<string> choix_possibles;
        choix_possibles.push_back("0");
        choix_possibles.push_back("1");
        cin>>menu_ligne;
        while (find(choix_possibles.begin(), choix_possibles.end(), menu_ligne) == choix_possibles.end() ){
            cout << "Choix incorrect, veuillez essayer de nouveau :" << endl;
            cin>>menu_ligne;
        }
        cout << endl  << endl;
        return(menu_ligne == "1");
}
