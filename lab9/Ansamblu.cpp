#include "Ansamblu.h"

Ansamblu::Ansamblu(): pa()
{
    vec = NULL;
    nr_caracteristici = 0;
    caracteristici = NULL;
}

Ansamblu::Ansamblu(Piesa_A & p, Piesa_B * pb, const int nc, string * c): 
                    pa(p), nr_caracteristici(nc)
{
    vec = new Piesa_B[pa.getGauri()];
    for(int i = 0; i < pa.getGauri(); i++)
        vec[i] = pb[i];
    caracteristici = new string[nr_caracteristici];
    for(int i = 0; i < nr_caracteristici; i++)
        caracteristici[i] = c[i];
}

Ansamblu::Ansamblu(const Ansamblu & a)
{
    *this = a;
}

Ansamblu::~Ansamblu()
{
    delete[] vec;
    delete[] caracteristici;
}

Ansamblu & Ansamblu::operator=(const Ansamblu & a)
{
    nr_caracteristici = a.nr_caracteristici;
    // if( vec != NULL ) delete[] vec;
    // if( caracteristici != NULL ) delete[] caracteristici;
    pa = a.pa;
    vec = new Piesa_B[a.pa.getGauri()];
    for(int i = 0; i < a.pa.getGauri(); i++)
        vec[i] = a.vec[i];
    caracteristici = new string[nr_caracteristici];
    for(int i = 0; i < nr_caracteristici; i++)
        caracteristici[i] = a.caracteristici[i];
    return *this;
}

istream & Ansamblu::citire(istream & dev)
{
    cout << "\n\nCITIRE\n\n--------------------\n--------------------";
    dev >> pa;
    vec = new Piesa_B[pa.getGauri()];
    for(int i = 0; i < pa.getGauri(); i++)
        dev >> vec[i];
    cout << "\nNumar caracteristici: ";
    dev >> nr_caracteristici;
    caracteristici = new string[nr_caracteristici];
    cout << "\nCaracteristici:\n";
    for(int i = 0; i < nr_caracteristici; i++)
        dev >> caracteristici[i];
    return dev;
}

ostream & Ansamblu::afisare(ostream & dev)
{
    cout << "\n\nAFISARE\n--------------------\n--------------------";
    cout << "\nAnsamblu\n\n";
    dev << pa;
    for(int i = 0; i < pa.getGauri(); i++)
        dev << vec[i];
    cout << "\nNumar caracteristici: ";
    dev << nr_caracteristici;
    cout << "\n\nCaracteristici:\n";
    for(int i = 0; i < nr_caracteristici; i++)
    {
        dev << caracteristici[i];
        cout << "\n";
    }

    cout << "\n";
    return dev;
}

istream & operator>>(istream & dev, Ansamblu & a)
{
    return a.citire(dev);
}

ostream & operator<<(ostream & dev, Ansamblu & a)
{
    return a.afisare(dev);
}

void Ansamblu::afisare()
{
    cout << *this;
}

int Ansamblu::getPret() const
{
    int s = pa.getPret();
    for(int i = 0; i < pa.getGauri(); i++)
        s = s + vec[i].getPret();
    return s;
}

void Ansamblu::afisareFisier(ostream & out)
{
    pa.afisareFisier(out);
    for(int i = 0; i < pa.getGauri(); i++)
        vec[i].afisareFisier(out);
    out << nr_caracteristici << " ";
    for(int i = 0; i < nr_caracteristici; i++)
        out << caracteristici[i] << " ";
}
