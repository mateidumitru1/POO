#include "produs_mixt.h"

produs_mixt::produs_mixt(): ps()
{   
    nr_functionalitati = 0;
}

produs_mixt::produs_mixt(const produs_software & p, vector<string> v, const int nr, const modul_hardware & mh): ps(p), functionalitati(v), nr_functionalitati(nr), modul_hardware(mh) {}

produs_mixt::produs_mixt(const int p, vector<string> v, const int nr, vector<Piesa> vp, const int nrp, const int pmp, const int nro): ps(p), functionalitati(v), nr_functionalitati(nr), modul_hardware(vp, nrp, pmp, nro) {}

produs_mixt::produs_mixt(const produs_mixt & pm): modul_hardware(pm.vec, pm.nr_piese, pm.pm, pm.nr_ore)
{
    ps = pm.ps;
    functionalitati = pm.functionalitati;
    nr_functionalitati = pm.nr_functionalitati;
}

produs_mixt & produs_mixt::operator=(const produs_mixt & pm)
{
    modul_hardware::operator=(pm);
    ps = pm.ps;
    functionalitati = pm.functionalitati;
    nr_functionalitati = pm.nr_functionalitati;
    return *this;
}

void produs_mixt::afisare(ostream & out)
{
    out << "\n******** Produs mixt ********\n";
    ps.afisare(out);
    modul_hardware::afisare(out);
    out << "\nNumar functionalitati: " << nr_functionalitati << "\n";
    out << "\nFunctionalitati:\n";
    for(int i = 0; i < functionalitati.size(); i++)
        out << functionalitati[i] << "\n";
    out << "\n";
}

int produs_mixt::getPret() const
{
    return ps.getPret() + modul_hardware::getPret(); 
}
