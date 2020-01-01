#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node
{
    public:
        Node(string id); //constructeur
        Node(int id);  //constructeur
        virtual ~Node();
        int getIdNode();  // récupère idNode d'un objet Node
        Node* previous; // le noeud de type previous sert dans l'algorithme de calcul de plus court chemin
        void setDistanceFromStart(int dist, bool minChangement); // change la distance de l'objet Node, càd la distance parcouru au sens de l'algorithme
        int getDistanceFromStart(bool minChangement); // récupère la distance de l'objet Node, càd la distance parcouru au sens de l'algorithme (depuis le point de départ)
        void initialiserNode(); // réinitialise le Node (distance et previous) avant de relancer l'algorithme (depuis le point de départ)
    protected:

    private:
        int idNode; //identifiant de l'arret
        int distanceFromStartCourtChemin; //distance depuis le noeud de départ (avec critère du chemin le plus court)
        int distanceFromStartMinChangement; //distance depuis le noeud de départ (avec critère du minimum de changement)
};

#endif // NODE_H
