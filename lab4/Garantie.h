#include <bits/stdc++.h>
using namespace std;

#ifndef garantie
#define garantie

class Garantie{
    private:
        int nr_luni;
        char *service;
    public:
        Garantie();
        Garantie(int, const char*);
        Garantie(const Garantie &);
        Garantie & operator=(const Garantie &);
        ~Garantie();
        friend istream & operator>>(istream &, Garantie &);
        friend ostream & operator<<(ostream &, Garantie &);
        friend int getperioada(Garantie &);
        friend char * getservice(Garantie &);
};

#endif