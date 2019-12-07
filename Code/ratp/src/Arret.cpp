#include "Arret.h"
#include <iostream>
#include <sstream>
using namespace std;

Arret::Arret(int id, string nom, string adresse, float x, float y)
{
    stop_id = id;
    this->nom = nom;
    this->adresse = adresse;
    stop_lon = x; stop_lat = y;
}
Arret::Arret(string id, string nom, string adresse, string x, string y)
{
    stringstream temp_id(id);
    temp_id >> stop_id;
    stringstream temp_lat(x);
    temp_lat >> stop_lat;
    stringstream temp_lon(y);
    temp_lon >> stop_lon;
    this->nom = nom;
    this->adresse = adresse;
}

void Arret::affiche()
{
    cout <<"stop id " << stop_id << " ; nom " << nom <<
    " ; adresse "  << adresse << " ; coord : [" <<
    stop_lon << ","  << stop_lat <<"]" << endl;
}
int Arret::getId(){
    return(stop_id);
}

string Arret::getNom(){
    return(nom);
}
string Arret::getAdresse(){
    return(adresse);
}
