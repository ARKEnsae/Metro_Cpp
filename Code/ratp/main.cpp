#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Arret.h"
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
    string chemin_s = "W:/Bureau/ProjetCpp/ProjetC/Data projet/RATP_GTFS_METRO_1/stops.txt";
    const char* chemin = chemin_s.c_str();
    int nb_lignes = nombre_lignes(chemin) - 1;

    ifstream fichier(chemin);

    int stop_id;
    float stop_lat,stop_lon;
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
        stringstream temp_id(stop_id_s);
        temp_id >> stop_id;
        stringstream temp_lat(stop_lat_s);
        temp_lat >> stop_lat;
        stringstream temp_lon(stop_lon_s);
        temp_lon >> stop_lon;

        //cout << stop_id <<" , "<< stop_name  << " , " << stop_desc << endl;

        Arret a(stop_id, stop_name, stop_desc,
                    stop_lat, stop_lon);
        a.affiche();

    }
//    for (int i = 0; i < 3; i++) {
////        fichier >> stop_id
////            >> stop_code
////            >> stop_name
////            >> stop_desc
////            >> stop_lat
////            >> stop_lon
////            >> location_type
////            >> parent_station;
//        getline(fichier, stop_id, ",");
//        getline(fichier, stop_code, ",");
//        getline(fichier, stop_name, ",");
//        getline(fichier, stop_desc, ",");
//        getline(fichier, stop_lat, ",");
//        getline(fichier, stop_lon, ",");
//        getline(fichier, location_type, ",");
//        getline(fichier, parent_station, ",");
//
//
//    }

    return 0;
}
