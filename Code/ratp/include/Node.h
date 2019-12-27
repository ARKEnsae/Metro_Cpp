#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Arret.h"
#include "Ligne.h"
#include "Metro.h"

using namespace std;
class Metro;

class Node
{
    public:
        Node(std::string id, Metro* metro);
        virtual ~Node();
        int getId();
        Node* previous;
        int distanceFromStart;
        Arret* getArret();
        string getNom();
        bool memeLigne (Node* node);
        bool memeArret (Node* node);
        Ligne* getLigne (Node* node);
    protected:

    private:
        Arret* arret;

};

#endif // NODE_H