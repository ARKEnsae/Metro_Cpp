#ifndef LIGNE_H
#define LIGNE_H

#include <vector>
#include "Arret.h"
#include <iostream>
using namespace std;

class Arret;

class Ligne
{
    public:
        Ligne(int idLigne, string numero_ligne, string nom_trajet, string couleur); // constructeur
        Ligne(string idLigne, string numero_ligne, string nom_trajet, string couleur); // constructeur
        virtual ~Ligne();
        void setArretsLigne(Arret* arret); // agrémente arretsLigne
        int getIdLigne(); // recupere idLigne
        string getNumero(); // recupere numero
        string getNom(); // recupere nom_trajet
        string getCouleur(); // recupere couleur
        string getDirection(); // recupere direction
        vector<Arret*> getArretsLigne(); //recupere arretsLigne
    private:
        vector<Arret*> arretsLigne; // liste des arrets de la ligne
        int idLigne; // identifiant de la ligne
        string numero_ligne; // numéro de ligne (ex : ligne 13)
        string nom_trajet; // nom du trajet ((CHATEAU DE VINCENNES <-> LA DEFENSE) - Retour)
        string couleur; // couleur de la ligne (NON UTILISE et mal renseigné par la RATP)
        string direction; // direction de la ligne, raccourci de nom_trajet adapté à l'algo (Ex LA DEFENSE)
};

#endif // LIGNE_H
