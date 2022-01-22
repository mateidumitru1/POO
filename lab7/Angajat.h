#include "Persoana.h"

#ifndef angajat
#define angajat

class Angajat: virtual public Persoana
{
    int id_angajat;
    int salariu;
    public:
        Angajat();
        Angajat(const int, const int);
        Angajat(const Angajat &);
        Angajat & operator=(const Angajat &);
        istream & citire(istream &);
        ostream & afisare(ostream &);
        void afisare();
        friend istream & operator>>(istream &, Angajat &);
        friend ostream & operator<<(ostream &, Angajat &);
        int getVenit(); // salariu
};

#endif
