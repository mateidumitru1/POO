#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef proprietate
#define proprietate

class Proprietate{
    protected:
        char cod[6];
        double valoare;
    public:
        Proprietate();
        Proprietate(char const *, double);
        Proprietate(const Proprietate &);
        Proprietate & operator=(const Proprietate &);
        istream & citire(istream &);
        ostream & afisare(ostream &);
        friend istream & operator>>(istream &, Proprietate &);
        friend ostream & operator<<(ostream &, Proprietate &);
        double getvenit();
        void sortare(Proprietate **, int);
        double getvaloare();
        virtual void pseudoAfisare();
};

#endif
