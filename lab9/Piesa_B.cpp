#include "Piesa_B.h"

Piesa_B::Piesa_B()
{
    culoare = '\0';
}

Piesa_B::Piesa_B(const int p, const char * c, const string s): Piesa(c, p), culoare(s){}

Piesa_B::Piesa_B(const Piesa_B & pb): Piesa(pb), culoare(pb.culoare){}

Piesa_B & Piesa_B::operator=(const Piesa_B & pb)
{
    Piesa::operator=(pb);
    culoare = pb.culoare;
    return *this;
}

istream & Piesa_B::citire(istream & dev)
{
    cout << "\nPiesa B\n\n\n";
    Piesa::citire(dev);
    cout << "\nCuloare: "; dev >> culoare;
    cout << "--------------------\n--------------------\n";
    return dev;
}

ostream & Piesa_B::afisare(ostream & dev)
{
    cout << "\nPiesa B\n\n";
    Piesa::afisare(dev);
    cout << "\nCuloare: "; dev << culoare;
    cout << "\n--------------------\n--------------------\n";
    return dev;
}

istream & operator>>(istream & dev, Piesa_B & pb)
{
    return pb.citire(dev);
}

ostream & operator<<(ostream & dev, Piesa_B & pb)
{
    return pb.afisare(dev);
}

void Piesa_B::afisare()
{
    cout << *this;
}

int Piesa_B::getPret() const
{
    return pret;
}

void Piesa_B::afisareFisier(ostream & out)
{
    Piesa::afisareFisier(out);
    out << culoare << " ";
}
