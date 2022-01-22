#include "Proprietate.h"

Proprietate::Proprietate()
{
    cod[0]= '\0';
    valoare= 0;
}

Proprietate::Proprietate(char const *c, double n): valoare(n)
{
    strcpy(cod, c);
}

Proprietate::Proprietate(const Proprietate & p): valoare(p.valoare)
{
    strcpy(cod, p.cod);
}

Proprietate & Proprietate::operator=(const Proprietate & p)
{
    valoare= p.valoare;
    if( cod[0] != '\0' ) cod[0]= '\0';
    strcpy(cod, p.cod);
    return *this;
}

istream & Proprietate::citire(istream & a)
{
    cout<<"Cod: "; a>>cod;
    cout<<"Valoare: "; a>>valoare;
    return a;
}

istream & operator>>(istream & a, Proprietate & p)
{
    return p.citire(a);
}

ostream & Proprietate::afisare(ostream & a)
{
    cout<<"\nCod: ";
    a<<cod;
    cout<<"\nValoare: ";
    a<<valoare;
    cout<<"\n";
    return a;
}

ostream & operator<<(ostream & a, Proprietate & p)
{
    return p.afisare(a);
}

double Proprietate::getvenit()
{
    return 0;
}

void Proprietate::sortare(Proprietate **v, int n)
{

    cout << "nope";
}

double Proprietate::getvaloare()
{
    return valoare;
}

void Proprietate::pseudoAfisare()
{
    cout << "\nProprietate\n";
    cout << "Cod: " << cod << endl;
    cout << "Valoare: " << valoare << endl;
}
