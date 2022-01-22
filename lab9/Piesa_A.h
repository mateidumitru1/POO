#ifndef PIESA_A
#define PIESA_A

#include "Piesa.h"

class Piesa_A: public Piesa
{
    int gauri;
    public:
        Piesa_A();
        Piesa_A(const int, const char *, const int);
        Piesa_A(const Piesa_A &);
        Piesa_A & operator=(const Piesa_A &);
        istream & citire(istream &);
        ostream & afisare(ostream &);
        friend istream & operator>>(istream &, Piesa_A &);
        friend ostream & operator<<(ostream &, Piesa_A &);
        int getGauri() const;
        void afisare();
        int getPret() const;
        void afisareFisier(ostream &);
};

#endif
