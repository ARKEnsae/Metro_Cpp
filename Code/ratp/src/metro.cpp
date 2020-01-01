#include "Metro.h"
#include <iomanip>
#include <fstream>
#include "Arret.h"
#include <sstream>
#include <algorithm>
#include <vector>

Metro::Metro()
{
    //ctor
}

Metro::~Metro()
{
    //dtor
}

void Metro::setArretsMetro(Arret* arret)
{
    arretsMetro.push_back(arret);
}

//Pour importer tous les arrets d'un fichier stop.txt
void Metro::importerStopTxt(string path_fichier)
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
        this->setArretsMetro(new Arret(stop_id_s, stop_name, stop_desc,
                                    stop_lat_s, stop_lon_s));
    }
    fichier.close();
}
bool Metro::importerLigneTxt(string path_fichier)
{
    bool fileExists = false;
    const char* chemin = path_fichier.c_str();

    ifstream fichier(chemin);
    if(fichier)
    {
        fileExists = true;
        string trip_id, idArret, arrival_time, departure_time, stop_sequence,
               stop_name,stop_desc, stop_lat, stop_lon, idLigne, service_id,
               route_short_name, route_long_name, route_color;
        string str;
        getline(fichier, str); /*On enlève la première ligne*/
        getline(fichier, str);
        stringstream ligne_fichier(str);

        getline(ligne_fichier, trip_id, '\t');
        getline(ligne_fichier, idArret, '\t');
        getline(ligne_fichier, arrival_time, '\t');
        getline(ligne_fichier, departure_time, '\t');
        getline(ligne_fichier, stop_sequence, '\t');
        getline(ligne_fichier, stop_name, '\t');
        getline(ligne_fichier, stop_desc, '\t');
        getline(ligne_fichier, stop_lat, '\t');
        getline(ligne_fichier, stop_lon, '\t');
        getline(ligne_fichier, idLigne, '\t');
        getline(ligne_fichier, service_id, '\t');
        getline(ligne_fichier, route_short_name, '\t');
        getline(ligne_fichier, route_long_name, '\t');
        getline(ligne_fichier, route_color, '\t');

        route_long_name.erase(remove(route_long_name.begin(), route_long_name.end(), '\"' ),route_long_name.end());
        route_short_name.erase(remove(route_short_name.begin(), route_short_name.end(), '\"' ),route_short_name.end());
        route_color.erase(remove(route_color.begin(), route_color.end(), '\"' ),route_color.end());

        this->lignesMetro.push_back(new Ligne(idLigne, route_short_name, route_long_name, route_color));

        // Maintenant on associer arret et ligne

        this->getLigne(idLigne)->setArretsLigne(this->getArret(idArret));
        this->getArret(idArret)->setLignesArret(this->getLigne(idLigne));
        while( getline(fichier, str) )
        {
            stringstream ligne_fichier(str);


            getline(ligne_fichier, trip_id, '\t');
            getline(ligne_fichier, idArret, '\t');
            getline(ligne_fichier, arrival_time, '\t');
            getline(ligne_fichier, departure_time, '\t');
            getline(ligne_fichier, stop_sequence, '\t');
            getline(ligne_fichier, stop_name, '\t');
            getline(ligne_fichier, stop_desc, '\t');
            getline(ligne_fichier, stop_lat, '\t');
            getline(ligne_fichier, stop_lon, '\t');
            getline(ligne_fichier, idLigne, '\t');
            getline(ligne_fichier, service_id, '\t');
            getline(ligne_fichier, route_short_name, '\t');
            getline(ligne_fichier, route_long_name, '\t');
            getline(ligne_fichier, route_color, '\t');
            this->getLigne(idLigne)->setArretsLigne(this->getArret(idArret));
            this->getArret(idArret)->setLignesArret(this->getLigne(idLigne));
        }
    }
    fichier.close();
    return(fileExists);
}
void Metro::importerTousStopTxt(string wd)
{
    const char* working_directory = wd.c_str();
    char num_lignes[16][3]= {"1", "2", "3", "3b", "4", "5",
                             "6", "7", "7b", "8", "9", "10", "11", "12", "13", "14"
                            };
    for (int i = 0; i < 16; i++)
    {
        char chemin[100];
        sprintf(chemin,
                "%s/Data projet/RATP_GTFS_METRO_%s/stops_a.txt",
                working_directory,
                num_lignes[i]);
        string chemin_fichier = chemin;
        this->importerStopTxt(chemin_fichier);
    }
}
void Metro::importerToutesLignesTxt(string wd)
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

        while(this->importerLigneTxt(chemin))
        {
            j++;
            sprintf(chemin,
                    "%s/Data projet/RATP_GTFS_METRO_%s/route_%i.txt",
                    working_directory,
                    num_lignes[i], j);
        }
    }
}
void Metro::importerDonnees(string wd)
{
    this->importerTousStopTxt(wd);
    this->importerToutesLignesTxt(wd);
}

Arret* Metro::getArret(int idArret)
{
    int i=0;
    for(i; i < arretsMetro.size(); ++i)
    {
        if(idArret == arretsMetro[i]->getIdArret())
            break;
    }
    if(i >=arretsMetro.size())
        throw runtime_error ("id non trouvé !");

    return(arretsMetro[i]);
}
Arret* Metro::getArret(string idArret)
{
    int stop_id_int;
    stringstream temp_id(idArret);
    temp_id >> stop_id_int;
    return(this->getArret(stop_id_int));
}
Ligne* Metro::getLigne(int idLigne)
{
    int i=0;
    for(i; i < arretsMetro.size(); ++i)
    {
        if(idLigne == lignesMetro[i]->getIdLigne())
            break;
    }
    if(i >=lignesMetro.size())
        throw runtime_error ("id non trouvé !");

    return(lignesMetro[i]);
}
Ligne* Metro::getLigne(string idLigne)
{
    int route_id_int;
    stringstream temp_id(idLigne);
    temp_id >> route_id_int;
    return(this->getLigne(route_id_int));
}

vector<Ligne*> Metro::getLignesMetro()
{
    return(lignesMetro);
}
