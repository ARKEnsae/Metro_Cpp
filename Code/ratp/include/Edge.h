#ifndef EDGE_H
#define EDGE_H
#include "Node.h"
using namespace std;

class Edge
{
    public:
    Node* node1;
    Node* node2;
    int distance;

    public:
         Edge(Node* node1, Node* node2, int distance);
         Edge();
         bool Connects(Node* node1, Node* node2);
        virtual ~Edge();

    protected:

    private:
};

#endif // EDGE_H
