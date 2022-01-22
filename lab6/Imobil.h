#include "Proprietate.h"

#ifndef imobil
#define imobil

class Imobil: public Proprietate{
    double venit_pe_an;
    char *imbunatatiri;
    public:
        Imobil();
        Imobil(double, const char *, const Proprietate &);
        Imobil(const Imobil &);
        ~Imobil();
        Imobil & operator=(const Imobil &);
        virtual istream & citire(istream &);
        virtual ostream & afisare(ostream &);
        friend istream & operator>>(istream &, Imobil &);
        friend ostream & operator<<(ostream &, Imobil &);
        virtual double getvenit();
        virtual double getvaloare();
        void pseudoAfisare();
};

#endif
