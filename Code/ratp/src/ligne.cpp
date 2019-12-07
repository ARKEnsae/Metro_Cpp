#include "Ligne.h"
#include <iostream>
#include <sstream>
using namespace std;

Ligne::Ligne(int route_id, int numero_ligne, string nom_trajet, string couleur)
{
    this->route_id = route_id;
    this->numero_ligne = numero_ligne;
    this->nom_trajet = nom_trajet;
    this->couleur = couleur;
}
Ligne::Ligne(string route_id, string numero_ligne, string nom_trajet, string couleur)
{
    stringstream temp_id(route_id);
    temp_id >> this->route_id;
    stringstream temp_num(numero_ligne);
    temp_num >> this->numero_ligne;
    this->nom_trajet = nom_trajet;
    this->couleur = couleur;
}

Ligne::~Ligne()
{
    //dtor
}
 void Ligne::ajouteArret(Arret* arret){
    liste_arrets.push_back(arret);
}
int Ligne::getId(){
    return(route_id);
}
int Ligne::getNumero(){
    return(numero_ligne);
}
string Ligne::getNom(){
    return(nom_trajet);
}
string Ligne::getCouleur(){
    return(couleur);
}
