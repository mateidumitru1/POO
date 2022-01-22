#include <bits/stdc++.h>

using namespace std;

#ifndef angajat
#define angajat

class Angajat{
    char *nume;
    char CNP[14];
    int salariu;
    
    public:
        Angajat();
        Angajat(char *, char[], int);
        Angajat(const Angajat &);
        ~ Angajat();
        void afisare() const;
        void modificare(const Angajat &);
        int getSalariu() const;
        bool eFemeie() const;
        void sortare(Angajat *, int);
};

#endif
