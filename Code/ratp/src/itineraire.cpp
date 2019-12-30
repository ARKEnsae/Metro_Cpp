#include "Itineraire.h"
#include "Metro.h"
#include "Node.h"
#include <vector>
#include <algorithm>

Itineraire::Itineraire(Node* destination, Metro metro)
{
    temps_total = destination->getDistance(false);
    Node* previous = destination;
    arrets.push_back(metro.getArret(previous->getId()));
    while (previous)
    {
        arrets.push_back(metro.getArret(previous->getId()));
        previous = previous->previous;
    }
    reverse(arrets.begin(),arrets.end());
}

Itineraire::~Itineraire()
{
    //dtor
}

vector<Arret*> Itineraire::getArrets(){
    return(arrets);
}

int Itineraire::getTempsTotal(){
    return(temps_total);
}

vector<Arret*> Itineraire::creerItineraireSimplifie()
{
    vector<Arret*> it_simplifie ; // à retourner
    it_simplifie.push_back(arrets[0]);
    for(int i=1; i< (arrets.size()-1); ++i)
    {
        if(!(arrets[i-1]->memeArret(arrets[i]))){
            if(!arrets[i-1]->memeLigne(arrets[i])){
                it_simplifie.push_back(arrets[i]);
            }
        }
    }
    it_simplifie.push_back(arrets[arrets.size()-1]);
    return(it_simplifie);
}
vector<int> Itineraire::creerNbArretsSimplifie()
{
    vector<int> nb_arrets; //à retourner
    int nb = 0;
    nb_arrets.push_back(0); // premier indice non important, par symétrie avec creerItineraireSimplifie
    for(int i=1; i< (arrets.size()-1); ++i)
    {
        if(!(arrets[i-1]->memeArret(arrets[i]))){
            ++nb;
            if(!arrets[i-1]->memeLigne(arrets[i])){
                nb_arrets.push_back(nb-1);
                nb = 0;
            }
        }
    }
    nb_arrets.push_back(nb);
    return(nb_arrets);
}

