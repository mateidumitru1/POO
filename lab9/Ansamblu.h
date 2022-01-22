#ifndef ANSAMBLU
#define ANSAMBLU
#include "Interfata.h"
#include "Piesa_A.h"
#include "Piesa_B.h"

class Ansamblu: virtual public Interfata
{
    Piesa_A pa;
    Piesa_B * vec;
    int nr_caracteristici;
    string * caracteristici;
    public:
        Ansamblu();
        Ansamblu(Piesa_A &, Piesa_B *, const int, string *);
        Ansamblu(const Ansamblu &);
        ~Ansamblu();
        Ansamblu & operator=(const Ansamblu &);
        istream & citire(istream &);
        ostream & afisare(ostream &);
        void afisare();
        friend istream & operator>>(istream &, Ansamblu &);
        friend ostream & operator<<(ostream &, Ansamblu &);
        int getPret() const;
        void afisareFisier(ostream &);
};

#endif
