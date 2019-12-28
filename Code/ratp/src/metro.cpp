#include "Metro.h"
#include <iomanip>
#include <fstream>
#include "Arret.h"
#include <sstream>
#include <algorithm>
#include <vector>
#include<limits>

Metro::Metro()
{
    //ctor
    itineraire = new Itineraire();
}

Metro::~Metro()
{
    //dtor
}

void Metro::ajouteArret(Arret* arret)
{
    liste_arrets.push_back(arret);
    liste_noms_arrets.push_back(arret->getNom());
}

//Pour ajouter tous les arrets d'un fichier stop.txt
void Metro::ajouteStopTxt(string path_fichier)
{
    const char* chemin = path_fichier.c_str();

    ifstream fichier(chemin);
    string stop_code, stop_name, stop_desc,
           parent_station, location_type,
           stop_lat_s, stop_lon_s, stop_id_s;
    string str;
    getline(fichier, str); /*On enlève la première ligne*/
    while( getline(fichier, str) )
    {
        stringstream ligne_fichier(str);

        getline(ligne_fichier, stop_id_s, ',');
        getline(ligne_fichier, stop_code, ',');
        getline(ligne_fichier, stop_name, ',');
        getline(ligne_fichier, stop_desc, ',');
        getline(ligne_fichier, stop_lat_s, ',');
        getline(ligne_fichier, stop_lon_s, ',');
        stop_name.erase(remove(stop_name.begin(), stop_name.end(), '\"' ),stop_name.end());
        stop_desc.erase(remove(stop_desc.begin(), stop_desc.end(), '\"' ),stop_desc.end());
        //Arret arret(stop_id_s, stop_name, stop_desc,
        //            stop_lat_s, stop_lon_s);
        //arret.affiche();
        this->ajouteArret(new Arret(stop_id_s, stop_name, stop_desc,
                                    stop_lat_s, stop_lon_s));
    }
    fichier.close();
}
bool Metro::ajouteLigne(string path_fichier)
{
    bool fileExists = false;
    const char* chemin = path_fichier.c_str();

    ifstream fichier(chemin);
    if(fichier)
    {
        fileExists = true;
        string trip_id, stop_id, arrival_time, departure_time, stop_sequence,
               stop_name,stop_desc, stop_lat, stop_lon, route_id, service_id,
               route_short_name, route_long_name, route_color;
        string str;
        getline(fichier, str); /*On enlève la première ligne*/
        getline(fichier, str);
        stringstream ligne_fichier(str);

        getline(ligne_fichier, trip_id, '\t');
        getline(ligne_fichier, stop_id, '\t');
        getline(ligne_fichier, arrival_time, '\t');
        getline(ligne_fichier, departure_time, '\t');
        getline(ligne_fichier, stop_sequence, '\t');
        getline(ligne_fichier, stop_name, '\t');
        getline(ligne_fichier, stop_desc, '\t');
        getline(ligne_fichier, stop_lat, '\t');
        getline(ligne_fichier, stop_lon, '\t');
        getline(ligne_fichier, route_id, '\t');
        getline(ligne_fichier, service_id, '\t');
        getline(ligne_fichier, route_short_name, '\t');
        getline(ligne_fichier, route_long_name, '\t');
        getline(ligne_fichier, route_color, '\t');

        route_long_name.erase(remove(route_long_name.begin(), route_long_name.end(), '\"' ),route_long_name.end());
        route_short_name.erase(remove(route_short_name.begin(), route_short_name.end(), '\"' ),route_short_name.end());
        route_color.erase(remove(route_color.begin(), route_color.end(), '\"' ),route_color.end());

        this->liste_lignes.push_back(new Ligne(route_id, route_short_name, route_long_name, route_color));

        // Maintenant on associer arret et ligne

        this->getLigne(route_id)->ajouteArret(this->getArret(stop_id));
        this->getArret(stop_id)->associeLigne(this->getLigne(route_id));
        while( getline(fichier, str) )
        {
            // str.replace(str.find("a"),0,"e"); //kim
            stringstream ligne_fichier(str);


            getline(ligne_fichier, trip_id, '\t');
            getline(ligne_fichier, stop_id, '\t');
            getline(ligne_fichier, arrival_time, '\t');
            getline(ligne_fichier, departure_time, '\t');
            getline(ligne_fichier, stop_sequence, '\t');
            getline(ligne_fichier, stop_name, '\t');
            getline(ligne_fichier, stop_desc, '\t');
            getline(ligne_fichier, stop_lat, '\t');
            getline(ligne_fichier, stop_lon, '\t');
            getline(ligne_fichier, route_id, '\t');
            getline(ligne_fichier, service_id, '\t');
            getline(ligne_fichier, route_short_name, '\t');
            getline(ligne_fichier, route_long_name, '\t');
            getline(ligne_fichier, route_color, '\t');
            this->getLigne(route_id)->ajouteArret(this->getArret(stop_id));
            this->getArret(stop_id)->associeLigne(this->getLigne(route_id));
        }
    }
    fichier.close();
    return(fileExists);
}
void Metro::ajouteTousStopTxt(string wd)
{
    const char* working_directory = wd.c_str();
    char num_lignes[16][3]= {"1", "2", "3", "3b", "4", "5",
                             "6", "7", "7b", "8", "9", "10", "11", "12", "13", "14"
                            };
    for (int i = 0; i < 16; i++)
    {
        char chemin[100];
        sprintf(chemin,
                "%s/Data projet/RATP_GTFS_METRO_%s/stops_a.txt", //stops.txt
                working_directory,
                num_lignes[i]);
        string chemin_fichier = chemin;
        this->ajouteStopTxt(chemin_fichier);
    }
}
void Metro::ajouteToutesLignes(string wd)
{
    const char* working_directory = wd.c_str();
    char num_lignes[16][3]= {"1", "2", "3", "3b", "4", "5",
                             "6", "7", "7b", "8", "9", "10", "11", "12", "13", "14"
                            };
    for (int i = 0; i < 16; i++)
    {
        int j = 1;
        char chemin[100];
        sprintf(chemin,
                "%s/Data projet/RATP_GTFS_METRO_%s/route_%i.txt",
                working_directory,
                num_lignes[i], j);

        while(this->ajouteLigne(chemin))
        {
            j++;
            sprintf(chemin,
                    "%s/Data projet/RATP_GTFS_METRO_%s/route_%i.txt",
                    working_directory,
                    num_lignes[i], j);
        }
    }
}
void Metro::chargeDonnees(string wd)
{
    this->ajouteTousStopTxt(wd);
    this->ajouteToutesLignes(wd);
    itineraire->chargerDonnees(wd, this);
}
void Metro::majNodes(string wd){
    itineraire = new Itineraire();
    itineraire->chargerDonnees(wd, this);
}

Arret* Metro::getArret(int stop_id)
{
    int i=0;
    for(i; i < liste_arrets.size(); ++i)
    {
        if(stop_id == liste_arrets[i]->getId())
            break;
    }
    if(i >=liste_arrets.size())
        throw runtime_error ("id non trouvé !");

    return(liste_arrets[i]);
}
Arret* Metro::getArret(string stop_id)
{
    int stop_id_int;
    stringstream temp_id(stop_id);
    temp_id >> stop_id_int;
    return(this->getArret(stop_id_int));
}
Ligne* Metro::getLigne(int route_id)
{
    int i=0;
    for(i; i < liste_arrets.size(); ++i)
    {
        if(route_id == liste_lignes[i]->getId())
            break;
    }
    if(i >=liste_lignes.size())
        throw runtime_error ("id non trouvé !");

    return(liste_lignes[i]);
}
Ligne* Metro::getLigne(string route_id)
{
    int route_id_int;
    stringstream temp_id(route_id);
    temp_id >> route_id_int;
    return(this->getLigne(route_id_int));
}


// KIM NEW
vector<Ligne*> Metro::getLignes()
{
    return(liste_lignes);
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
vector<string> Metro::menu()
{

    cout<<endl<<" ----------------------- MENU -----------------------"<<endl<<endl;

    vector<string> partie_menu;
    partie_menu.push_back("de depart");
    partie_menu.push_back("d'arrivee");
    vector<string> identifiants_depart_arrivee;

    vector<string> id_ligne;
    for(int i = 0; i < liste_lignes.size(); ++i){
        id_ligne.push_back(liste_lignes[i]->getNumero());
    }
    std::vector<string>::iterator it = std::unique (id_ligne.begin(), id_ligne.end());                                                          //                ^
    id_ligne.resize(std::distance(id_ligne.begin(),it) );



    for(int m = 0; m < 2; m++)
    {
        vector<Ligne*> lignes_entree;
        cout<<endl<<"Choisissez votre ligne " << partie_menu[m] <<" parmi les lignes suivantes : " << endl;
        //cout<< "1, 2, 3, '3B', 4, 5, 6, 7, '7B', 8, 9, 10, 11, 12, 13 et 14" <<endl<<endl;
        //Ajout Alain
        cout << id_ligne[0];
        for(int i = 1; i < (id_ligne.size()-1); ++i){
            cout << ", " << id_ligne[i];
        }
        cout << " et " << id_ligne[id_ligne.size()-1] << endl;
        //Ajout Alain fin
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

bool Metro::menuItineraire(){
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

bool Metro::menuQuitter(){
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

