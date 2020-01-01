#include "Itineraire.h"
#include "Metro.h"
#include "Node.h"
#include <vector>
#include <algorithm>

Itineraire::Itineraire(Node* destination, Metro metro)
{
    tempsTotal = destination->getDistanceFromStart(false);
    Node* previous = destination;
    arretsItineraire.push_back(metro.getArret(previous->getIdNode()));
    while (previous)
    {
        arretsItineraire.push_back(metro.getArret(previous->getIdNode()));
        previous = previous->previous;
    }
    reverse(arretsItineraire.begin(),arretsItineraire.end());
}

Itineraire::~Itineraire()
{
    //dtor
}

int Itineraire::getTempsTotal(){
    return(tempsTotal);
}

vector<Arret*> Itineraire::creerItineraireSimplifie()
{
    vector<Arret*> it_simplifie ;
    it_simplifie.push_back(arretsItineraire[0]);
    for(int i=1; i< (arretsItineraire.size()-1); ++i)
    {
        if(!(arretsItineraire[i-1]->memeArret(arretsItineraire[i]))){
            if(!arretsItineraire[i-1]->memeLigne(arretsItineraire[i])){
                it_simplifie.push_back(arretsItineraire[i]);
            }
        }
    }
    it_simplifie.push_back(arretsItineraire[arretsItineraire.size()-1]);
    return(it_simplifie);
}


vector<int> Itineraire::creerNbArretsSimplifie()
{
    vector<int> nb_arrets;
    int nb = 0;
    nb_arrets.push_back(0); // premier indice non important, par symétrie avec creerItineraireSimplifie
    for(int i=1; i< (arretsItineraire.size()-1); ++i)
    {
        if(!(arretsItineraire[i-1]->memeArret(arretsItineraire[i]))){
            ++nb;
            if(!arretsItineraire[i-1]->memeLigne(arretsItineraire[i])){
                nb_arrets.push_back(nb-1);
                nb = 0;
            }
        }
    }
    nb_arrets.push_back(nb);
    return(nb_arrets);
}
