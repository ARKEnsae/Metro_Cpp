#include "Arret.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>


Arret::Arret(int id, string nom, string adresse, float x, float y)
{
    idArret = id;
    this->nom = nom;
    this->adresse = adresse;
    stop_lon = x; stop_lat = y;
}
Arret::Arret(string id, string nom, string adresse, string x, string y)
{
    stringstream temp_id(id);
    temp_id >> idArret;
    stringstream temp_lat(x);
    temp_lat >> stop_lat;
    stringstream temp_lon(y);
    temp_lon >> stop_lon;
    this->nom = nom;
    this->adresse = adresse;
}
void Arret::setLignesArret(Ligne* ligne){
    this->lignesArret.push_back(ligne);
}

int Arret::getIdArret(){
    return(idArret);
}

string Arret::getNom(){
    return(nom);
}
string Arret::getAdresse(){
    return(adresse);
}
vector<Ligne*> Arret::getLignesArret(){
    return(lignesArret);
}
bool Arret::memeArret (Arret* arret){
    return((this->nom == arret->getNom()) &(lignesArret[0]->getNumero()==arret->getLignesArret()[0]->getNumero()));
}
bool Arret::memeLigne (Arret* arret){
    vector<Ligne*> autres_lignes = arret->getLignesArret();
    return(lignesArret[0]->getNumero()==autres_lignes[0]->getNumero());
}

// A partir d'un arret, récupérer son indice dans une liste d'arrêts.
// Mais cet arrêt peut en fait ne pas appartenir à cette liste d'arrêts.
int getIndArret(vector<Arret*> liste_arrets, Arret* arret){
    int i=0;
    for(i; i < liste_arrets.size(); ++i){
        if(arret->getNom() == liste_arrets[i]->getNom())
            break;
    }
    return(i);
}


vector<string> Arret::calculerDirection(Arret* arret){
    vector<Arret*> arrets;
    vector<string> resultat;

    for(int i=0; i < lignesArret.size(); ++i){
        arrets = lignesArret[i]->getArretsLigne();
        int j = getIndArret(arrets, this);
        int k = getIndArret(arrets, arret);
        if(k<arrets.size() && j < k){
            resultat.push_back(lignesArret[i]->getNumero());
            resultat.push_back(lignesArret[i]->getDirection());
            return(resultat);
        }
    }
    //Non trouvé : c'est forcément l'inverse des lignes de this :
    resultat.push_back(lignesArret[0]->getNumero());
    resultat.push_back(lignesArret[0]->getNom());
    size_t aller = resultat[1].find("Aller");
    if (aller!=std::string::npos){//On veut donc le retour
        resultat[1] =  resultat[1].substr(1, resultat[1].find(" <->")-1);
    } else {//On veut donc l'aller
        size_t retour = resultat[1].find("Retour");
        resultat[1] = resultat[1].substr(resultat[1].find(" <->")+5, retour-4);
    }
    return(resultat);
}

