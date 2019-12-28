#ifndef ITINERAIRE_H
#define ITINERAIRE_H
#include "itineraire.h"
#include <vector>
#include "Arret.h"
#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Metro.h"

class Node;
class Edge;
class Metro;

class Itineraire
{
    public:
        itineraire();
        void DijkstrasFinal(string entree, string sortie, bool min_itineraire);
        void chargerDonnees(string wd, Metro* metro);
    protected:

    private:
        vector<Node*> nodes;
        vector<Edge*> edges;
        void chargerNodes(string chemin, Metro* metro);
        void chargerEdges(string chemin);
        Node* ExtractSmallest(vector<Node*>& nodes, bool min_itineraire);
        bool Contains(vector<Node*>& nodes, Node* node);
        vector<Node*>* AdjacentRemainingNodes(Node* node);
        int Distance(Node* node1, Node* node2, bool min_itineraire);
        void PrintShortestRouteTo(Node* destination);
        void Dijkstras(bool min_itineraire);
        vector<Edge*>* AdjacentEdges(vector<Edge*>& edges, Node* node);
        void RemoveEdge(vector<Edge*>& edges, Edge* edge);
        int getIndiceFromNode(string identifiant, vector<Node*> les_noeuds);

};

#endif // ITINERAIRE_H
