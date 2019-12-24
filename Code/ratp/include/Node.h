#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node
{
    public:
        Node(std::string id);
        virtual ~Node();
        std::string id; //char
        Node* previous;
        int distanceFromStart;


    protected:

    private:
};

#endif // NODE_H
