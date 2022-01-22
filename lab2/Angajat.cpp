#include <iostream>
#include "Angajat.h"

Angajat::Angajat()
{
    nume= NULL;
    strcpy(CNP, "0000000000000");
    salariu= 0;
}

Angajat::Angajat(char *c, char ch[], int n)
{
    nume= strdup(c);
    strcpy(CNP, ch);
    salariu= n;
}

Angajat::Angajat(const Angajat & a)
{
    modificare(a);
}

Angajat::~ Angajat()
{
    delete[] nume;
}

void Angajat::afisare() const
{
    cout<<"Nume: "<<nume<<"\n";
    cout<<"CNP: "<<CNP<<"\n";
    cout<<"Salariu: "<<salariu<<"\n\n";
}

void Angajat::modificare(const Angajat & a)
{
    nume= strdup(a.nume);
    strcpy(CNP, a.CNP);
    salariu= a.salariu;
}

int Angajat::getSalariu() const
{
    return salariu;
}

bool Angajat::eFemeie() const
{
    if( CNP[0] == '2' || CNP[0] == '4' || CNP[0] == '6' ) return true;
    return false;
}

void Angajat::sortare(Angajat *a, int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if((strcmp(a[i].nume, a[j].nume)) > 0) swap(a[i], a[j]);
}
