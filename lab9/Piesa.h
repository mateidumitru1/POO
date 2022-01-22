#ifndef PIESA_H
#define PIESA_H

#include "Interfata.h"
#include <bits/stdc++.h>
using namespace std;

class Piesa: virtual public Interfata
{
    protected: 
        char cod[4];
        int pret;
    public:
        Piesa();
        Piesa(const char *, const int);
        Piesa(const Piesa &);
        Piesa & operator=(const Piesa &);
        virtual istream & citire(istream &);
        virtual ostream & afisare(ostream &);
        friend istream & operator>>(istream &, Piesa &);
        friend ostream & operator<<(ostream &, Piesa &);
        void afisare();
        int getPret();
        void afisareFisier(ostream &);
};

#endif
