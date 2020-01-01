#ifndef METRO_H
#define METRO_H
#include "Arret.h"
#include "Ligne.h"
#include <vector>

#include <iostream>

class Metro
{
    public:
        Metro();
        virtual ~Metro();
        void importerDonnees(string wd); // charge l'ensemble des données (applique les fonctions importerTousStopTxt et importerToutesLignesTxt)
        Arret* getArret(int idArret); // récupère un objet Arret à partir d'un identifiant de type int
        Arret* getArret(string idArret); // récupère un objet Arret à partir d'un identifiant de type string
        Ligne* getLigne(int idLigne); // récupère un objet Ligne à partir d'un identifiant de type int
        Ligne* getLigne(string idLigne); // récupère un objet Ligne à partir d'un identifiant de type int
        vector<Ligne*> getLignesMetro(); // recupere lignesMetro

    protected:

    private:
        vector<Arret*> arretsMetro; // tous les arrets de metro
        vector<Ligne*> lignesMetro; // toutes les lignes de metro
        void setArretsMetro(Arret* arret); //agrementer arretsMetro
        void importerStopTxt(string path_fichier); // importer un arret dans les données de C++
        void importerTousStopTxt(string wd); // importer TOUS LES arrets dans les données de C++
        bool importerLigneTxt(string path_fichier); // importer une ligne dans les données de C++
        void importerToutesLignesTxt(string wd); // importer TOUTES LES lignes dans les données de C++
};

#endif // METRO_H
