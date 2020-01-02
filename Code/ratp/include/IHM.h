#ifndef IHM_H
#define IHM_H
#include <iostream>
#include "Metro.h"
#include "Itineraire.h"
#include <windows.h> //couleurs palette

class IHM
{
    public:
        IHM(bool activerCouleur); //constructeur
        virtual ~IHM();
        vector<string> choixDepartArrivee(Metro metro); // menu : choisir la station de départ et d'arrivee
        bool choixTypeItineraire(); // menu : affiche le choix d'itineraire (entre plus court chemin et minimum de changement)
        void afficherItineraire(Itineraire itineraire); //menu : affiche l'itinéraire en sortie d'algo
        bool quitter(); // menu : quitte l'application
    protected:

    private:
#ifdef _WINDOWS_H
        HANDLE hConsole; //objet de type HANDLE permettant de colorer la console sur windows
#endif
        bool activerCouleur; //booleen qui vaut TRUE si on veut colorer la console (windows) et FALSE sinon
        void colorerEcran(int code_couleur); // fonction qui colore l'écran

};

#endif // IHM_H
