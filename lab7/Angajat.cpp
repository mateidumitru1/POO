#include "Angajat.h"

Angajat::Angajat()
{
    id_angajat = 0;
    salariu = 0;
}

Angajat::Angajat(const int id, const int s): id_angajat(id), salariu(s){}

Angajat::Angajat(const Angajat & a): id_angajat(a.id_angajat), salariu(a.salariu){}

Angajat & Angajat::operator=(const Angajat & a)
{
    id_angajat = a.id_angajat;
    salariu = a.salariu;
    return *this;
}

istream & Angajat::citire(istream & o)
{
    cout<<"Id angajat: "; o>>id_angajat;
    cout<<"Salariu: "; o>>salariu;
    return o;
}

istream & operator>>(istream & o, Angajat & a)
{
    return a.citire(o);
}

ostream & Angajat::afisare(ostream & o)
{
    cout<<"\nId angajat: "; o<<id_angajat;
    cout<<"\nSalariu: "; o<<salariu;
    return o;
}

ostream & operator<<(ostream & o, Angajat & a)
{
    return a.afisare(o);
}

void Angajat::afisare()
{
    cout<<"\nId angajat: " << id_angajat;
    cout<<"\nSalariu: " << salariu;
}

int Angajat::getVenit()
{
    return salariu;
}
