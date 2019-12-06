#ifndef ITINERAIRE_H
#define ITINERAIRE_H

#include <vector>
#include "Arret.h"
#include <iostream>
using namespace std;


class itineraire
{
    public:
        itineraire();
        virtual ~itineraire();

    protected:

    private:
        vector<Arret> liste_arrets;
};

#endif // ITINERAIRE_H
