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
        void ajouteArret(Arret arret);
        void ajouteStopTxt(string path_fichier);
        void ajouteTousStopTxt(string wd);
        Arret getArret(int stop_id);
        Arret getArret(string stop_id);
    protected:

    private:
        vector<Arret> liste_arrets;
        vector<string> liste_noms_arrets;
        vector<Ligne> liste_lignes;
};

#endif // METRO_H
