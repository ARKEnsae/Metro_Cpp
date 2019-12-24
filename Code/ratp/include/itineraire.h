#ifndef ITINERAIRE_H
#define ITINERAIRE_H

#include <vector>
#include "Arret.h"
#include <iostream>
#include "Node.h"
#include "Edge.h"
using namespace std;


class itineraire
{
    public:
        itineraire();
        virtual ~itineraire();
        Node* ExtractSmallest(vector<Node*>& nodes);
        bool Contains(vector<Node*>& nodes, Node* node);
        vector<Node*>* AdjacentRemainingNodes(Node* node);
        int Distance(Node* node1, Node* node2);
        void PrintShortestRouteTo(Node* destination);
        void Dijkstras();
        vector<Edge*>* AdjacentEdges(vector<Edge*>& edges, Node* node);
        void RemoveEdge(vector<Edge*>& edges, Edge* edge);
        int getIndiceFromNode(std::string identifiant ,vector<Node*> les_noeuds);


    protected:

    private:
        vector<Arret*> liste_arrets;
        vector<Node*> nodes;
        //vector<Edge*> edges;
        Edge** edges;

};

#endif // ITINERAIRE_H
