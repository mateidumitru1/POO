#include "Garantie.h"

Garantie::Garantie()
{
    nr_luni= 0;
    service= NULL;
}

Garantie::Garantie(int n, const char *c)
{
    nr_luni= n;
    service= strdup(c);
}

Garantie::Garantie(const Garantie & p)
{
    nr_luni= p.nr_luni;
    service= strdup(p.service);
}

Garantie & Garantie::operator=(const Garantie & p)
{
    nr_luni= p.nr_luni;
    if(service != NULL) delete[] service;
    service= strdup(p.service);
    return *this;
}

Garantie::~Garantie()
{
    if(service != NULL) delete[] service;
}


istream & operator>>(istream & pp, Garantie & p)
{
    cout<<"Nr. luni: ";
    pp>>p.nr_luni;
    cout<<"Service: ";
    char s[40];
    pp.get();
    pp.get(s,40);
    pp.get();
    p.service= strdup(s);
    cout<<"\n";
    return pp;
}

ostream & operator<<(ostream & pp, Garantie & p)
{

    cout<<"-----------------------\nGARANTIE\nNr. luni: ";
    pp<<p.nr_luni;
    cout<<"\nService: ";
    pp<<p.service;
    cout<<"\n\n";
    return pp;
}

int getperioada(Garantie & g)
{
    return g.nr_luni;
}

char * getservice(Garantie & g)
{
    return g.service;
}
