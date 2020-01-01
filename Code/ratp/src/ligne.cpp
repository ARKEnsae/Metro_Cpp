#include "Ligne.h"
#include <iostream>
#include <sstream>
#include <string>

Ligne::Ligne(int idLigne, string numero_ligne, string nom_trajet, string couleur)
{
    this->idLigne = idLigne;
    this->numero_ligne = numero_ligne;
    this->nom_trajet = nom_trajet;
    this->couleur = couleur;
}
Ligne::Ligne(string idLigne, string numero_ligne, string nom_trajet, string couleur)
{
    stringstream temp_id(idLigne);
    temp_id >> this->idLigne;
    this->numero_ligne = numero_ligne;
    this->nom_trajet = nom_trajet;
    this->couleur = couleur;
    size_t aller = nom_trajet.find("Aller");
    this->direction = nom_trajet;
    if (aller!=std::string::npos){
        string direction = nom_trajet.substr(nom_trajet.find(" <->")+5, aller-4);
        direction = direction.substr(0, direction.find("Aller")-4);
        this->direction = direction;
    } else {
        this->direction =  nom_trajet.substr(1, nom_trajet.find(" <->")-1);
    }

}

Ligne::~Ligne()
{
    //dtor
}
 void Ligne::setArretsLigne(Arret* arret){
    arretsLigne.push_back(arret);
}
int Ligne::getIdLigne(){
    return(idLigne);
}
string Ligne::getNumero(){
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
vector<Arret*> Ligne::getArretsLigne(){
    return(arretsLigne);
}

