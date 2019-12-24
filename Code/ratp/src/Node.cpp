#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(std::string id)
        : id(id), previous(NULL), distanceFromStart(INT_MAX)
{
}

Node::~Node()
{
    //dtor
}
