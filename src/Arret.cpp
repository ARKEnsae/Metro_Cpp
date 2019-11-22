#include "Arret.h"
#include <iostream>
using namespace std;

Arret::Arret(int id, string nom, string adresse, float x, float y)
{
    stop_id = id; nom = nom; adresse = adresse; stop_lon = x; stop_lat = y;
}

Arret::~Arret()
{
    //dtor
}
