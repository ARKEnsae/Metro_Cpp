#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node
{
    public:
        Node(string id);
        Node(int id);
        virtual ~Node();
        int getId();
        Node* previous;
        void setDistance(int dist, bool min_itineraire);
        int getDistance(bool min_itineraire);
        void reinitialiseNode();
    protected:

    private:
        int id_arret;
        int distanceFromStart;
        int distanceFromStartMinChangement;
};

#endif // NODE_H
