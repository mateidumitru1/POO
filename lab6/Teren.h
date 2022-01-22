#include "Proprietate.h"

#ifndef teren
#define teren

class Teren: public Proprietate{
    double venit_pe_luna_m2;
    double suprafata;
    public:
        Teren();
        Teren(const double, const double, const Proprietate &);
        Teren(const Teren &);
        Teren & operator=(const Teren &);
        virtual istream & citire(istream &);
        virtual ostream & afisare(ostream &);
        friend istream & operator>>(istream &, Teren &);
        friend ostream & operator<<(ostream &, Teren &);
        virtual double getvenit();
        virtual double getvaloare();
        virtual void pseudoAfisare();
};

#endif
