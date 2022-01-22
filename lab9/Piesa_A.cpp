#include "Piesa_A.h"

Piesa_A::Piesa_A()
{
    gauri = 0;
}

Piesa_A::Piesa_A(const int p, const char * c, const int g): gauri(g), Piesa(c, p){}

Piesa_A::Piesa_A(const Piesa_A & pa): gauri(pa.gauri), Piesa(pa.cod, pa.pret){}

Piesa_A & Piesa_A::operator=(const Piesa_A & pa)
{
    Piesa::operator=(pa);
    gauri = pa.gauri;
    return *this;
}

istream & Piesa_A::citire(istream & dev)
{
    cout << "\n\nPiesa A\n\n\n";
    Piesa::citire(dev);
    cout << "\nGauri: "; dev >> gauri;
    cout << "--------------------\n--------------------\n";
    return dev;
}

ostream & Piesa_A::afisare(ostream & dev)
{
    cout << "\nPiesa A\n\n";
    Piesa::afisare(dev);
    cout << "\nGauri: "; dev << gauri;
    cout << "\n--------------------\n--------------------\n";
    return dev;
}

istream & operator>>(istream & dev, Piesa_A & pa)
{
    return pa.citire(dev);
}

ostream & operator<<(ostream & dev, Piesa_A & pa)
{
    return pa.afisare(dev);
}

int Piesa_A::getGauri() const
{
    return gauri;
}

void Piesa_A::afisare()
{
    cout << *this;
}

int Piesa_A::getPret() const
{
    return pret;
}

void Piesa_A::afisareFisier(ostream & out)
{
    Piesa::afisareFisier(out);
    out << gauri << " ";
}
