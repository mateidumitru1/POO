#include "Piesa.h"

Piesa::Piesa()
{
    cod[0] = '\0';
    pret = 0;
}

Piesa::Piesa(const char *c, const int p): pret(p)
{
    strcpy(cod, c);
}

Piesa::Piesa(const Piesa & p): pret(p.pret)
{
    strcpy(cod, p.cod);
}

Piesa & Piesa::operator=(const Piesa & p)
{
    strcpy(cod, p.cod);
    pret = p.pret;
    return *this;
}

istream & Piesa::citire(istream & dev)
{
    cout << "Cod: "; dev >> cod;
    cout << "\nPret: "; dev >> pret;
    return dev;
}

ostream & Piesa::afisare(ostream & dev)
{
    cout << "\nCod: "; dev << cod;
    cout << "\n\nPret: "; dev << pret;
    cout << "\n";
    return dev;
}

istream & operator>>(istream & dev, Piesa & p)
{
    return p.citire(dev);
}

ostream & operator<<(ostream & dev, Piesa & p)
{
    return p.afisare(dev);
}

void Piesa::afisare()
{
    cout << *this;
}

int Piesa::getPret()
{
    return pret;
}

void Piesa::afisareFisier(ostream & out)
{
    out << cod << " " << pret << " ";
}
