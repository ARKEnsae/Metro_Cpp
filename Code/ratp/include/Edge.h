#ifndef EDGE_H
#define EDGE_H
#include "Node.h"

class Node;
class Edge
{
    public:
        Node* node1; //noeud de depart du lien
        Node* node2; //noeud d'arrivee du lien
        Edge(Node* node1, Node* node2, int distanceCourtChemin, int distanceMinChangement); //constructeur
        Edge();
        bool connects(Node* node1, Node* node2); // indique si deux noeuds sont connectes
        virtual ~Edge();
        int getDistance(bool MinChangement); //recupere la distance associe a l'objet Edge (distance entre deux noeuds càd entre 2 arrêts de metro)
    protected:

    private:
        int distanceCourtChemin;
        int distanceMinChangement;
};

#endif // EDGE_H
