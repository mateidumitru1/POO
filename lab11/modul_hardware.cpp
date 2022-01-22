#include "modul_hardware.h"

Piesa::Piesa()
{
    cod[0] = '\0';
    pret = 0;
}

Piesa::Piesa(const char ch[], const int p): pret(p)
{
    strcpy(cod, ch);
}

Piesa::Piesa(const Piesa & p)
{
    strcpy(cod, p.cod);
    pret = p.pret;
}

Piesa & Piesa::operator=(const Piesa & p)
{
    strcpy(cod, p.cod);
    pret = p.pret;
    return *this;
}

void Piesa::afisare(ostream & out)
{
    out << "\nCod: " << cod << "\nPret: " << pret << "\n";
}

int Piesa::getPret() const
{
    return pret;
}


modul_hardware::modul_hardware()
{
    nr_piese = 0;
    pm = 0;
    nr_ore = 0;
}

modul_hardware::modul_hardware(vector<Piesa> v, const int nr, const int p, const int ore): vec(v), nr_piese(nr), pm(p), nr_ore(ore) {}

modul_hardware::modul_hardware(const modul_hardware & mh): vec(mh.vec), nr_piese(mh.nr_piese), pm(mh.pm), nr_ore(mh.nr_ore) {}

modul_hardware & modul_hardware::operator=(const modul_hardware & mh)
{
    vec = mh.vec;
    nr_piese = mh.nr_piese;
    pm = mh.pm;
    nr_ore = mh.nr_ore;
    return *this;
}

void modul_hardware::afisare(ostream & out)
{
    out << "\n********  Modul Hardware ********\n\nPiese:\n\n";
    out << "Numar piese: " << nr_piese << "\n";
    for(int i = 0; i < vec.size(); i++)
    {
        out << "\nPiesa " << i + 1;
        vec[i].afisare(out);
    }

    out << "\nPret manopera: " << pm;
    out << "\nNumar ore: " << nr_ore << "\n";
}

int modul_hardware::getPret() const
{
    int pret = 0;
    for(int i = 0; i < vec.size(); i++)
        pret = pret + vec[i].getPret();
    pret = pret + pm * nr_ore;
    return pret;
}
