#ifndef EDGE_H
#define EDGE_H
#include "Node.h"
using namespace std;

class Node;
class Edge
{
    public:
        Node* node1;
        Node* node2;
        Edge(Node* node1, Node* node2, int distance);
        Edge();
        bool Connects(Node* node1, Node* node2);
        virtual ~Edge();
        int getDistance(bool min_itineraire);
    protected:

    private:
        int distance;
        int distance_changement;
};

#endif // EDGE_H
