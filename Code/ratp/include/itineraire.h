#ifndef ITINERAIRE_H
#define ITINERAIRE_H

#include "Arret.h"
#include "Metro.h"
#include "Node.h"

#include <vector>

class Itineraire
{
    public:
        Itineraire(Node* destination, Metro metro);
        virtual ~Itineraire();
        vector<Arret*> getArrets();
        int getTempsTotal();
        vector<Arret*> creerItineraireSimplifie();
        vector<int> creerNbArretsSimplifie();
    private:
        vector<Arret*> arrets;
        int temps_total;
};

#endif // ITINERAIRE_H
