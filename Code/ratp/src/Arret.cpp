#include "Arret.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
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
void Arret::associeLigne(Ligne* ligne){
    this->lignes.push_back(ligne);
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
vector<Ligne*> Arret::getLigne(){
    return(lignes);
}
bool Arret::memeArret (Arret* arret){
    //return(this->nom == arret->getNom());
    if(this->lignes.size() == 0 | arret->getLigne().size() == 0){
        return(this->nom == arret->getNom());
    }
    return((this->nom == arret->getNom()) &(this->lignes == arret->getLigne()));
}
bool Arret::memeLigne (Arret* arret){
    vector<Ligne*> autres_lignes = arret->getLigne();
    /*bool resultat = false;
    for(int i=0; i < lignes.size(); ++i){
        for (int j = 0; j< autres_lignes.size(); j++){
            resultat = lignes[i]->getNumero() == autres_lignes[j]->getNumero();
            if(resultat)
                break;
        }
    }

    if(this->lignes.size() == 0 | arret->getLigne().size() == 0){
        return(this->nom == arret->getNom());
    }*/
    return(lignes[0]->getNumero()==autres_lignes[0]->getNumero());
}


int getIndArret(vector<Arret*> liste_arrets, Arret* arret){
    int i=0;
    for(i; i < liste_arrets.size(); ++i){
        if(arret->getNom() == liste_arrets[i]->getNom())
            break;
    }
    return(i);
}
vector<string> Arret::calculDestination(Arret* arret){
    vector<Arret*> arrets;
    vector<string> resultat;

    for(int i=0; i < lignes.size(); ++i){
        arrets = lignes[i]->getArrets();
        int j = getIndArret(arrets, this);
        int k = getIndArret(arrets, arret);
        //cout << endl <<  lignes[i]->getNom()<< endl;
        //cout << << lignes[i]->getNom() << endl;
        //cout << j << " et " << k << "et " << arrets.size() << (k<arrets.size() && j < k) << endl;
        if(k<arrets.size() && j < k){
            resultat.push_back(lignes[i]->getNumero());
            resultat.push_back(lignes[i]->getDirection());
            return(resultat);
        }
    }
    //Non trouvé : c'est forcément l'inverse des lignes de this :
    resultat.push_back(lignes[0]->getNumero());
    resultat.push_back(lignes[0]->getNom());
    size_t aller = resultat[1].find("Aller");
    if (aller!=std::string::npos){//On veut donc le retour
        resultat[1] =  resultat[1].substr(1, resultat[1].find(" <->")-1);
    } else {//On veut donc l'aller
        size_t retour = resultat[1].find("Retour");
        resultat[1] = resultat[1].substr(resultat[1].find(" <->")+5, retour-4);
    }
    return(resultat);
}
/*
Ligne* Arret::getLigne(Arret* arret){
    Ligne* result;
    vector<Arret*> arrets;
    vector<Arret*>::iterator it_actuel;
    vector<Arret*>::iterator it_destination;

    for(int i=0; i < lignes.size(); ++i){
        arrets = lignes[i]->getArrets();
        it_actuel = std::find(arrets.begin(), arrets.end(), this);
        it_destination = std::find(arrets.begin(), arrets.end(), arret);
        if(it_destination!=arrets.end() & it_actuel < it_destination){
            result = lignes[i];
            break;
        }
    }
    result = lignes[0];

    return(result);
}*/
