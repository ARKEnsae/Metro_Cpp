#ifndef ITINERAIRE_H
#define ITINERAIRE_H

#include "Arret.h"
#include "Metro.h"
#include "Node.h"

#include <vector>

class Itineraire
{
    public:
        Itineraire(Node* destination, Metro metro); // constructeur
        virtual ~Itineraire();
        int getTempsTotal(); // récupère tempsTotal
        vector<Arret*> creerItineraireSimplifie(); // A partir d'un vecteurs d'arrets (itinéraire)
        //créer un itinéraire simplifié c'est à dire en ne conservant que les arrêts pour lesquels on change de ligne
        vector<int> creerNbArretsSimplifie(); // A partir d'un vecteurs d'arrets (itinéraire)
        // calculer le temps passé entre deux arrêts d'un  itinéraire simplifié c'est à dire
        // l'itinéraire qui ne conserve que les arrêts pour lesquels on change de ligne

    private:
        vector<Arret*> arretsItineraire; // arrets parcourus durant l'itineraire
        int tempsTotal; // temps total pour parcourir l'ensemble de l'itineraire
};

#endif // ITINERAIRE_H
