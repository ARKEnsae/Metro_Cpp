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
        vector<Node*> it_simplifie; //NEW
        vector<int> nombre_arrets; //NEW
        Itineraire DijkstrasFinal(string entree, string sortie, bool min_itineraire); //NEW itineraire
        void chargerDonnees(string wd, Metro* metro);
    protected:

    private:
        // un itineraire c'est un ensemble de noeuds et de liens orientés initiaux
        // et un itineraire final : un nombre de noeuds restreint avec nombre d'arrets, ...
        //
        vector<Node*> nodes;
        vector<Edge*> edges;
        void chargerNodes(string chemin, Metro* metro);
        void chargerEdges(string chemin);
        Node* ExtractSmallest(vector<Node*>& nodes, bool min_itineraire);
        bool Contains(vector<Node*>& nodes, Node* node);
        vector<Node*>* AdjacentRemainingNodes(Node* node);
        int Distance(Node* node1, Node* node2, bool min_itineraire);
        void PrintShortestRouteTo(Node* destination);
        int CalculerTempsMin(vector<Node*> it_simplifie); //NEW
        Itineraire CalculerItineraire(Node* destination); //NEW
        void Dijkstras(bool min_itineraire);
        /*vector<Edge*>* AdjacentEdges(vector<Edge*>& edges, Node* node);*/
        /*void RemoveEdge(vector<Edge*>& edges, Edge* edge);*/
        int getIndiceFromNode(string identifiant, vector<Node*> les_noeuds);

};

#endif // ITINERAIRE_H
