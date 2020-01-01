#include "Edge.h"

Edge::Edge(Node* node1, Node* node2, int distanceCourtChemin, int distanceMinChangement)
        : node1(node1), node2(node2), distanceCourtChemin(distanceCourtChemin), distanceMinChangement(distanceMinChangement)
{

}

Edge::Edge()
        : distanceCourtChemin(0), distanceMinChangement(0)
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

int Edge::getDistance(bool min_itineraire){
    if(min_itineraire){
        return(distanceMinChangement);
    }else{
        return(distanceCourtChemin);
    }
}

 bool Edge::connects(Node* node1, Node* node2)
    {
        return (
                   (node1 == this->node1 &&
                    node2 == this->node2)
                )
                    ;
    }
