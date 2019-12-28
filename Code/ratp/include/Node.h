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
        Arret* getArret();
        string getNom();
        bool memeLigne (Node* node);
        bool memeArret (Node* node);
        vector<string> calculDestination(Node* node);
        void setDistance(int dist, bool min_itineraire);
        int getDistance(bool min_itineraire);
    protected:

    private:
        Arret* arret;
        int distanceFromStart;
        int distanceFromStartMinChangement;
};

#endif // NODE_H
