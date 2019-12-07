#include "Metro.h"
#include <iomanip>
#include <fstream>
#include "Arret.h"
#include <sstream>
#include <algorithm>
Metro::Metro()
{
    //ctor
}

Metro::~Metro()
{
    //dtor
}

void Metro::ajouteArret(Arret arret)
{
    liste_arrets.push_back(arret);
    liste_noms_arrets.push_back(arret.getNom());
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
        Arret arret(stop_id_s, stop_name, stop_desc,
                    stop_lat_s, stop_lon_s);
        //arret.affiche();
        this->ajouteArret(arret);
    }
}
void Metro::ajouteTousStopTxt(string wd)
{
    const char* working_directory = wd.c_str();
    char num_lignes[16][3]= {"1", "2", "3", "3b", "4", "5",
     "6", "7", "7b", "8", "9", "10", "11", "12", "13", "14"};
     for (int i = 0; i < 16; i++){
        char chemin[100];
        sprintf(chemin,
             "%s/Data projet/RATP_GTFS_METRO_%s/stops.txt",
              working_directory,
              num_lignes[i]);
        string chemin_fichier = chemin;
        this->ajouteStopTxt(chemin_fichier);
    }
}

Arret Metro::getArret(int stop_id)
{
    int i=0;
    for(i; i < liste_arrets.size(); ++i){
        if(stop_id == liste_arrets[i].getId())
            break;
    }
    if(i >=liste_arrets.size())
        throw runtime_error ("id non trouvé !");

    return(liste_arrets[i]);
}
Arret Metro::getArret(string stop_id)
{
    int stop_id_int;
    stringstream temp_id(stop_id);
    temp_id >> stop_id_int;
    return(this->getArret(stop_id_int));
}
