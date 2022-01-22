#include <iostream>
#include <bits/stdc++.h>
#include "Garantie.h"

using namespace std;

#ifndef produs
#define produs

class Produs{
    private:
        int pret;
        char *marca;
        Garantie g;
    public:
        Produs();
        Produs(int, const char*, Garantie);
        Produs(const Produs &);
        Produs & operator=(const Produs &);
        ~Produs();
        friend istream & operator>>(istream &, Produs &);
        friend ostream & operator<<(ostream &, Produs &);
        friend void sortare(Produs *, int);
        friend void garantie12(Produs *, int);
        friend void search_service(Produs *, int, const char *);
};

#endif