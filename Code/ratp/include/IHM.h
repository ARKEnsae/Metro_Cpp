#ifndef IHM_H
#define IHM_H
#include <iostream>
#include "Metro.h"

class IHM
{
    public:
        IHM();
        virtual ~IHM();
        vector<string> choixItineraire(Metro metro);
        bool choixTypeItineraire();
        bool quitter();
    protected:

    private:
};

#endif // IHM_H
