#ifndef IHM_H
#define IHM_H
#include <iostream>
#include "Metro.h"
#include "Itineraire.h"
#include <windows.h> //couleurs palette

class IHM
{
    public:
        IHM(bool activerCouleur);
        virtual ~IHM();
        vector<string> choixItineraire(Metro metro);
        bool choixTypeItineraire();
        bool quitter();
        void AfficherItineraire(Itineraire itineraire); //NEW
        void colorerEcran(int code_couleur);
    protected:

    private:
        HANDLE hConsole;
        bool activerCouleur;
};

#endif // IHM_H
