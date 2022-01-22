#ifndef PRODUS_SOFTWARE
#define PRODUS_SOFTWARE

#include <iostream>
#include "interface.h"
using namespace std;

class produs_software: virtual public Interface
{
    protected:
        int pret;
    public:
        produs_software();
        produs_software(const int);
        produs_software(const produs_software &);
        produs_software & operator=(const produs_software &);
        void afisare(ostream &);
        int getPret() const;
};

#endif
