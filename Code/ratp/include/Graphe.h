#ifndef GRAPHE_H
#define GRAPHE_H
#include <vector>
#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Metro.h"

class Node;
class Edge;

class Graphe
{
    public:
        Graphe(string wd);
        vector<Node*> it_simplifie; //NEW
        vector<int> nombre_arrets; //NEW
        Node* dijkstras(string entree, string sortie, bool min_itineraire); //NEW itineraire
        void reinitialiseNodes();
    protected:

    private:
        vector<Node*> nodes;
        vector<Edge*> edges;
        void chargerNodes(string chemin);
        void chargerEdges(string chemin, string chemin_changement);
        Node* ExtractSmallest(vector<Node*>& nodes, bool min_itineraire);
        bool Contains(vector<Node*>& nodes, Node* node);
        vector<Node*>* AdjacentRemainingNodes(Node* node);
        int Distance(Node* node1, Node* node2, bool min_itineraire);
        int getIndiceFromNode(string identifiant, vector<Node*> les_noeuds);

};

#endif // GRAPHE_H
