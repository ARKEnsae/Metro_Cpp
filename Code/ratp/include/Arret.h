#ifndef ARRET_H
#define ARRET_H
#include <iostream>
#include "Ligne.h"
using namespace std;

class Ligne;

class Arret
{
    public:
        Arret(int id, string nom, string adresse, float x, float y); //constructeur
        Arret(string id, string nom, string adresse, string x, string y); //constructeur
        int getIdArret(); //récupère idArret
        vector<Ligne*> getLignesArret(); // récupère lignesArret
        string getNom(); //récupère nom
        string getAdresse(); //récupère adresse
        void setLignesArret(Ligne* ligne); // agrémente "lignesArret"
        bool memeLigne (Arret* arret); //indique si deux arrêts appartiennent à la même ligne (même numéro de ligne Ex : ligne 13)
        bool memeArret (Arret* arret); //indique si deux arrêts sont en fait les mêmes (même numéro de ligne + même nom d'arrêt Ex : Gaité, ligne 13)
        vector<string> calculerDirection(Arret* arret); // A partir de deux arrêts en déduit une direction
        // Ex : Si l'arrêt 1 a pour nom Gaité  (ligne 13) et l'arret 2 a pour nom Pernety  (ligne 13)
       // alors la fonction me renvoie direction CHATILLON
    protected:
    private:
        int idArret; //identifiant de l'arret
        string nom; // nom de l'arret
        string adresse; //adresse de l'arret (NON UTILISE)
        float stop_lon; // longitude de l'arret (NON UTILISE)
        float stop_lat; // latitude de l'arret (NON UTILISE)
        vector<Ligne*> lignesArret; // lignes parcourus par l'arrêt
        // Rq : une ligne dans notre modélisation n'est pas "la ligne 13", il y a 4 lignes associés à la ligne 13 par exemple).
        // Cette modélisation s'adapte à la maniere dont la RATP a mis en forme ses donnees.
};

#endif // ARRET_H
