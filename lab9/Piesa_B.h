#ifndef PIESA_B
#define PIESA_B

#include "Piesa.h"

class Piesa_B: public Piesa
{
    string culoare;
    public:
        Piesa_B();
        Piesa_B(const int, const char *, const string);
        Piesa_B(const Piesa_B &);
        Piesa_B & operator=(const Piesa_B &);
        istream & citire(istream &);
        ostream & afisare(ostream &);
        friend istream & operator>>(istream &, Piesa_B &);
        friend ostream & operator<<(ostream &, Piesa_B &);
        void afisare();
        int getPret() const;
        void afisareFisier(ostream &);
};

#endif
