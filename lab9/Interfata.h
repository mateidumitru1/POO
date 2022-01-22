#ifndef INTERFATA_H
#define INTERFATA_H

#include <bits/stdc++.h>
using namespace std;

class Interfata
{
    public:
        virtual void afisareFisier(ostream &) = 0;
        virtual void afisare() = 0;
        virtual int getPret() const = 0;
};

#endif
