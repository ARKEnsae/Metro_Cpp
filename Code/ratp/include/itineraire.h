#ifndef ITINERAIRE_H
#define ITINERAIRE_H
#include "itineraire.h"
#include <vector>
#include "Arret.h"
#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Metro.h"
using namespace std;

class Node;
class Edge;
class Metro;

class Itineraire
{
    public:
        itineraire();
        Node* ExtractSmallest(vector<Node*>& nodes);
        bool Contains(vector<Node*>& nodes, Node* node);
        vector<Node*>* AdjacentRemainingNodes(Node* node);
        int Distance(Node* node1, Node* node2);
        void PrintShortestRouteTo(Node* destination);
        void Dijkstras();
        vector<Edge*>* AdjacentEdges(vector<Edge*>& edges, Node* node);
        void RemoveEdge(vector<Edge*>& edges, Edge* edge);
        int getIndiceFromNode(std::string identifiant ,vector<Node*> les_noeuds);
        void DijkstrasFinal(std::string entree,std::string sortie);
        void chargerDonnees(string wd, Metro metro);

    protected:

    private:
        vector<Arret*> liste_arrets;
        vector<Node*> nodes;
        //vector<Edge*> edges;
        vector<Edge*> edges;
        void chargerNodes(string chemin, Metro metro);
        void chargerEdges(string chemin);

};

#endif // ITINERAIRE_H
