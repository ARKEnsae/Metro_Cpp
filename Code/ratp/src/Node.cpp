#include "Node.h"
#include <iostream>
#include <sstream>

#define INT_MAX 10000000

Node::Node(string id)
        : previous(NULL), distanceFromStart(INT_MAX), distanceFromStartMinChangement(INT_MAX)
{
    stringstream temp_id(id);
    temp_id >> id_arret;
}
Node::Node(int id)
        : id_arret(id), previous(NULL), distanceFromStart(INT_MAX), distanceFromStartMinChangement(INT_MAX)
{
}

Node::~Node()
{
    //dtor
}

int Node::getId(){
    return(id_arret);
}

int Node::getDistance(bool min_itineraire){
    if(min_itineraire){
        return(distanceFromStartMinChangement);
    }else{
        return(distanceFromStart);
    }
}
void Node::setDistance(int dist, bool min_itineraire){
    if(min_itineraire){
        distanceFromStartMinChangement = dist;
    }else{
        distanceFromStart = dist;
    }
}
void Node::reinitialiseNode(){
    distanceFromStartMinChangement = INT_MAX;
    distanceFromStart = INT_MAX;
    previous = NULL;
}
