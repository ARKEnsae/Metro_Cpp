#include "Node.h"
#include <iostream>
#include <sstream>

#define INT_MAX 10000000 //La valeur que l'on donne à l'infini. Car en informatique, l'infini n'existe pas !

Node::Node(string id)
        : previous(NULL), distanceFromStartCourtChemin(INT_MAX), distanceFromStartMinChangement(INT_MAX)
{
    stringstream temp_id(id);
    temp_id >> idNode;
}
Node::Node(int id)
        : idNode(id), previous(NULL), distanceFromStartCourtChemin(INT_MAX), distanceFromStartMinChangement(INT_MAX)
{
}

Node::~Node()
{
    //dtor
}

int Node::getIdNode(){
    return(idNode);
}

int Node::getDistanceFromStart(bool min_itineraire){
    if(min_itineraire){
        return(distanceFromStartMinChangement);
    }else{
        return(distanceFromStartCourtChemin);
    }
}
void Node::setDistanceFromStart(int dist, bool min_itineraire){
    if(min_itineraire){
        distanceFromStartMinChangement = dist;
    }else{
        distanceFromStartCourtChemin = dist;
    }
}
void Node::reinitialiserNode(){
    distanceFromStartMinChangement = INT_MAX;
    distanceFromStartCourtChemin = INT_MAX;
    previous = NULL;
}
