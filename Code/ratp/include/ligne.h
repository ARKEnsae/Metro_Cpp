#ifndef LIGNE_H
#define LIGNE_H

#include <vector>
#include "Arret.h"
#include <iostream>
using namespace std;

class Arret;

class Ligne
{
    public:
        Ligne(int route_id, int numero_ligne, string nom_trajet, string couleur);
        Ligne(string route_id, string numero_ligne, string nom_trajet, string couleur);
        virtual ~Ligne();
        void ajouteArret(Arret* arret);
        int getId();
        int getNumero();
        string getNom();
        string getCouleur();
    private:
        vector<Arret*> liste_arrets;
        int route_id;
        int numero_ligne;
        string nom_trajet;
        string couleur;
};

#endif // LIGNE_H
//"trip_id"	"stop_id"	"arrival_time"	"departure_time"	"stop_sequence"	"stop_name"	"stop_desc"	"stop_lat"	"stop_lon"	"route_id"	"service_id"	"route_short_name"	"route_long_name"	"route_color"
