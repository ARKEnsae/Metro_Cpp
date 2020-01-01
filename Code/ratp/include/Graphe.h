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
        Graphe(string wd); // constructeur
        Node* dijkstras(string entree, string sortie, bool minChangement); //algo du plus court chemin
    protected:

    private:
        vector<Node*> nodes; //noeuds du graphe
        vector<Edge*> edges; //edges du graphe
        void importerNodes(string chemin); //importer les noeuds à partir d'une matrice en format txt
        void importerEdges(string chemin, string chemin_changement); //importer les edges à partir d'une matrice en format txt
        bool contains(vector<Node*>& nodes, Node* node); // booléen qui renvoie true si le node est bien contenu dans un vecteur de nodes
        int getIndiceFromNode(string identifiant, vector<Node*> les_noeuds); //renvoie l'emplacement d'un Node dans un vecteur de Nodes, à partir d'un idNode sélectionné

      // Les fonctions qui suivent concernent les differentes etapes de l'algorithme
        void initialiserNodes(); // initialise TOUS les Nodes (distance et previous) (utile lorsqu'on relance l'algorithme)
        Node* extractSmallest(vector<Node*>& nodes, bool minChangement); // renvoie le noeud le plus proche en distance d'un certain noeud parmi un vecteur de noeud
        vector<Node*>* adjacentRemainingNodes(Node* node); // renvoie les noeuds adjacents d'un noeud qui n'ont pas été parcourus
        int calculerDistance(Node* node1, Node* node2, bool minChangement); // calculer la distance entre deux neouds

};

#endif // GRAPHE_H
