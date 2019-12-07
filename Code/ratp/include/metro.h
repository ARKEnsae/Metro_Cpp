#ifndef METRO_H
#define METRO_H
#include <vector>
#include <iostream>
#include "Arret.h"
#include "ligne.h"

using namespace std;

class metro
{
    public:
        metro();
        virtual ~metro();

    protected:

    private:
        vector<Arret> liste_arrets;
        vector<ligne> liste_lignes;
};

#endif // METRO_H
