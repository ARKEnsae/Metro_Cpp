#include "Edge.h"

Edge::Edge(Node* node1, Node* node2, int distance)
        : node1(node1), node2(node2), distance(distance)
    {

    }

Edge::Edge()//NEW CONSTRUCTEUR KIM
        : distance(0)
    {
        Node* n1;
        node1 = n1;
        Node* n2;
        node2 = n2;
    }

Edge::~Edge()
{
    //dtor
}

 bool Edge::Connects(Node* node1, Node* node2)
    {
        return (
                   (node1 == this->node1 &&
                    node2 == this->node2)
                    //|| //dans le mauvais sens ?
                   //(node1 == this->node2 &&
                    //node2 == this->node1)
                )
                    ;
    }
