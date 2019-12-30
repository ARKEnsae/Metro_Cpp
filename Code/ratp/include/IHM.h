#ifndef IHM_H
#define IHM_H
#include <iostream>
#include "Metro.h"
#include "Itineraire.h"
#include <windows.h> //couleurs palette

class IHM
{
    public:
        HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //NEW
        IHM();
        virtual ~IHM();
        vector<string> choixItineraire(Metro metro);
        bool choixTypeItineraire();
        bool quitter();
        void AfficherItineraire(Itineraire itineraire); //NEW

    protected:

    private:
};

#endif // IHM_H
