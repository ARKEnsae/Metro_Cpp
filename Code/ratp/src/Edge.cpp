#include "Edge.h"

Edge::Edge(Node* node1, Node* node2, int distance)
        : node1(node1), node2(node2), distance(distance)
    {
        if(node1->memeLigne(node2)){
            distance_changement = 1;
        }else{
            distance_changement = 20;
        }
        //distance_changement = !node1->memeLigne(node2);
    }

Edge::Edge()//NEW CONSTRUCTEUR KIM
        : distance(0), distance_changement(0)
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
        return(distance_changement);
    }else{
        return(distance);
    }
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
