#include "Ligne.h"
#include <iostream>
#include <sstream>
#include <string>
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
    size_t aller = nom_trajet.find("Aller");
    this->direction = nom_trajet;
    if (aller!=std::string::npos){
        this->direction =  nom_trajet.substr(1, nom_trajet.find(" <->"));
    } else {
        string direction = nom_trajet.substr(nom_trajet.find(" <->")+5, nom_trajet.size());
        direction = direction.substr(0, direction.find("Retour")-4);
        this->direction = direction;
    }
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
string Ligne::getDirection(){
    return(direction);
}
vector<Arret*> Ligne::getArrets(){
    return(liste_arrets);
}
