#include "Produs.h"

Produs::Produs(): g()
{
    pret= 0;
    marca= 0;
}

Produs::Produs(int a, const char *c, Garantie p): g(p)
{
    pret= a;
    marca= strdup(c);
}

Produs::Produs(const Produs & p): g(p.g)
{
    pret= p.pret;
    marca= strdup(p.marca);
}

Produs & Produs::operator=(const Produs &p)
{
    pret= p.pret;
    if(marca != NULL) delete[] marca;
    marca= strdup(p.marca);
    g= p.g;
    return *this;
}

Produs::~Produs()
{
    if(marca != NULL) delete[] marca;
}

istream & operator>>(istream & pp, Produs & p)
{
    cout<<"Pret: "; pp>>p.pret;
    char s[40];
    pp.get();
    cout<<"Marca: ";
    pp.get(s,40);
    pp.get();
    p.marca= strdup(s);
    pp>>p.g;
    return pp;
}

ostream & operator<<(ostream & pp, Produs & p)
{

    cout<<"-----------------------\nPRODUS\nPret: ";
    pp<<p.pret;
    cout<<"\nMarca: ";
    pp<<p.marca;
    cout<<"\n";
    pp<<p.g;
    return pp;
}

void sortare(Produs *v, int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(v[i].pret > v[j].pret) swap(v[i],v[j]);
}

void garantie12(Produs *v, int n)
{
    for(int i=0;i<n;i++)
        if( getperioada(v[i].g) > 12 ) cout<<v[i];
}

void search_service(Produs *v, int n, const char *p)
{
    for(int i=0;i<n;i++)
        if( strcmp( getservice(v[i].g) , p) == 0 ) cout<<v[i];
}
