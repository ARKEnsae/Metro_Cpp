#ifndef ARRET_H
#define ARRET_H
#include <iostream>
#include "Ligne.h"
using namespace std;

class Ligne;

class Arret
{
    public:
        Arret(int id, string nom, string adresse, float x, float y);
        Arret(string id, string nom, string adresse, string x, string y);
        virtual void affiche();
        int getId();
        vector<Ligne*> getLigne();
        string getNom();
        string getAdresse();
        void associeLigne(Ligne* ligne);
        bool memeLigne (Arret* arret);
        bool memeArret (Arret* arret);
        Ligne* getLigne(Arret* arret);
        //bool operator< (Arret &other); //KIM
    protected:
    private:
        int stop_id;
        string nom;
        string adresse;
        float stop_lon;
        float stop_lat;
        vector<Ligne*> lignes;
};

#endif // ARRET_H
