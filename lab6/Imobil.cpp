#include "Imobil.h"

Imobil::Imobil()
{
    venit_pe_an= 0;
    imbunatatiri= NULL;
}

Imobil::Imobil(double d, const char *c, const Proprietate & p): venit_pe_an(d), Proprietate(p)
{
    imbunatatiri= strdup(c);
}

Imobil::Imobil(const Imobil & t): Proprietate(t), venit_pe_an(t.venit_pe_an)
{
    imbunatatiri= strdup(t.imbunatatiri);
}

Imobil::~Imobil()
{
    delete[] imbunatatiri;
}

Imobil & Imobil::operator=(const Imobil & t)
{
    Proprietate::operator=(t);
    if( imbunatatiri != NULL ) delete[] imbunatatiri;
    imbunatatiri= strdup(t.imbunatatiri);
    venit_pe_an= t.venit_pe_an;
    return *this;
}

istream & Imobil::citire(istream & a)
{
    Proprietate::citire(a);
    char *aux= new char[40];
    cout<<"Venit pe an: "; a>>venit_pe_an;
    cout<<"Imbunatatiri: "; a>>aux;
    imbunatatiri= strdup(aux);
    free(aux);
    return a;
}

istream & operator>>(istream & a, Imobil & t)
{
    return t.citire(a);
}

ostream & Imobil::afisare(ostream & a)
{
    Proprietate::afisare(a);
    cout<<"Venit pe an: "; a<<venit_pe_an;
    cout<<"\nImbunatatiri: "; a<<imbunatatiri;
    cout<<"\n";
    return a;
}

ostream & operator<<(ostream & a, Imobil & t)
{
    return t.afisare(a);
}

double Imobil::getvenit()
{
    return venit_pe_an / 12;
}

double Imobil::getvaloare()
{
    return valoare;
}

void Imobil::pseudoAfisare() {
    cout << "\nImobil:\n";
    cout << "Venit: " << venit_pe_an << endl;
    cout << "Imbunatatiri: " << imbunatatiri;
    cout << "\nCod: " << cod << endl;
    cout << "Valoare: " << valoare << endl;
}