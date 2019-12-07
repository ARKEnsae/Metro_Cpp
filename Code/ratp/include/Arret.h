#ifndef ARRET_H
#define ARRET_H
#include <iostream>
using namespace std;

class Arret
{
    public:
        Arret(int id, string nom, string adresse, float x, float y);
        virtual void affiche();
    protected:
    private:
        int stop_id;
        string nom;
        string adresse;
        float stop_lon;
        float stop_lat;
};

#endif // ARRET_H
