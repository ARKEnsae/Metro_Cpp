#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(string id, Metro metro)
        : previous(NULL), distanceFromStart(INT_MAX)
{
    this->arret = metro.getArret(id);
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
