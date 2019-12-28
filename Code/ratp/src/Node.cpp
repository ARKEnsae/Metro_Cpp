#include "Node.h"
#include <iostream>
#include "Arret.h"
#include "Ligne.h"
using namespace std;

Node::Node(string id, Metro* metro)
        : previous(NULL), distanceFromStart(INT_MAX), distanceFromStartMinChangement(INT_MAX)
{
    this->arret = metro->getArret(id);
}

Node::~Node()
{
    //dtor
}

int Node::getId(){
    return(arret->getId());
}

Arret* Node::getArret(){
    return(arret);
}

string Node::getNom(){
    return(arret->getNom());
}

bool Node::memeArret (Node* node){
    return(arret->memeArret(node->getArret()));
}
bool Node::memeLigne (Node* node){
    return(arret->memeLigne(node->getArret()));
}
vector<string> Node::calculDestination (Node* node){
    return(arret->calculDestination(node->getArret()));
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
