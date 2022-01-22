#include "Teren.h"

Teren::Teren()
{
    venit_pe_luna_m2= 0;
    suprafata= 0;
}

Teren::Teren(const double v, const double s, const Proprietate & p): venit_pe_luna_m2(v), suprafata(s), Proprietate(p){}

Teren::Teren(const Teren & t): Proprietate(t), venit_pe_luna_m2(t.venit_pe_luna_m2), suprafata(t.suprafata) {}

Teren & Teren::operator=(const Teren & t)
{
    Proprietate::operator=(t);
    venit_pe_luna_m2= t.venit_pe_luna_m2;
    suprafata= t.suprafata;
    return *this;
}

istream & Teren::citire(istream & a)
{
    Proprietate::citire(a);
    cout<<"Venit pe luna: "; a>>venit_pe_luna_m2;
    cout<<"Suprafata: "; a>>suprafata;
    return a;
}

istream & operator>>(istream & a, Teren & t)
{
    return t.citire(a);
}

ostream & Teren::afisare(ostream & a)
{
    Proprietate::afisare(a); //aici
    cout<<"Venit pe luna:"; a<<venit_pe_luna_m2;
    cout<<"\nSuprafata: "; a<<suprafata;
    cout<<"\n";
    return a;
}

ostream & operator<<(ostream & a, Teren & t)
{
    return t.afisare(a);
}

double Teren::getvenit()
{
    return venit_pe_luna_m2 * suprafata;
}

double Teren::getvaloare()
{
    return valoare;
}

void Teren::pseudoAfisare()
{
    cout << "\nTeren:\n";
    cout << "Venit: " << venit_pe_luna_m2 << endl;
    cout << "Suprafata: " << suprafata << endl;
    cout << "Cod: " << cod << endl;
    cout << "Valoare: " << valoare << endl;
}
