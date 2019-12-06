#include "Arret.h"
#include <iostream>
using namespace std;

Arret::Arret(int id, string nom, string adresse, float x, float y)
{
    stop_id = id;
    this->nom = nom;
    this->adresse = adresse;
    stop_lon = x; stop_lat = y;
}

void Arret::affiche()
{
    cout <<"stop id " << stop_id << " ; nom " << nom <<
    " ; adresse "  << adresse << " ; coord : [" <<
    stop_lon << ","  << stop_lat <<"]" << endl;
}

