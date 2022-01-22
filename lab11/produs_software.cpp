#include "produs_software.h"

produs_software::produs_software()
{
    pret = 0;
}

produs_software::produs_software(const int p): pret(p) {}

produs_software & produs_software::operator=(const produs_software & ps)
{
    pret = ps.pret;
    return *this;
}

produs_software::produs_software(const produs_software & ps)
{
    pret = ps.pret;
}

void produs_software::afisare(ostream & out)
{
    out << "\n******** Produs Software ********\n\nPret: " << pret << "\n";
}

int produs_software::getPret() const
{
    return pret;
}
