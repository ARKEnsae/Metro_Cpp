#ifndef LIGNE_H
#define LIGNE_H
#include "Arret.h"
#include <vector>
#include <iostream>
using namespace std;


class ligne
{
    public:
        ligne();
        virtual ~ligne();

    protected:

    private:
        string nom_ligne;
        int route_id;
        string route_color;
        vector<Arret> liste_arrets;

};

#endif // LIGNE_H
