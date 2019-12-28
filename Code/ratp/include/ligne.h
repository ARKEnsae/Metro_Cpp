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
        Ligne(int route_id, string numero_ligne, string nom_trajet, string couleur);
        Ligne(string route_id, string numero_ligne, string nom_trajet, string couleur);
        virtual ~Ligne();
        void ajouteArret(Arret* arret);
        int getId();
        string getNumero();
        string getNom();
        string getCouleur();
        string getDirection();
        vector<Arret*> getArrets();
    private:
        vector<Arret*> liste_arrets;
        int route_id;
        //int numero_ligne;
        string numero_ligne;
        string nom_trajet;
        string couleur;
        string direction;
};

#endif // LIGNE_H
