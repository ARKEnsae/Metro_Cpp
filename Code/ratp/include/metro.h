#ifndef METRO_H
#define METRO_H
#include "Arret.h"
#include "Ligne.h"
#include <vector>

#include <iostream>
using namespace std;


class Metro
{
    public:
        Metro();
        virtual ~Metro();
        void chargeDonnees(string wd);
        Arret* getArret(int stop_id);
        Arret* getArret(string stop_id);
        Ligne* getLigne(int route_id);
        Ligne* getLigne(string route_id);
    protected:

    private:
        void ajouteToutesLignes(string wd);
        void ajouteTousStopTxt(string wd);
        vector<Arret*> liste_arrets;
        vector<string> liste_noms_arrets;
        vector<Ligne*> liste_lignes;
        void ajouteStopTxt(string path_fichier);
        void ajouteArret(Arret* arret);
        bool ajouteLigne(string path_fichier);
};

#endif // METRO_H
