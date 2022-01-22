#ifndef MODUL_HARDWARE
#define MODUL_HARDWARE

#include <iostream>
#include <vector>
#include <cstring>
#include "interface.h"

using namespace std;


class Piesa
{
    char cod[6];
    int pret;
    public:
        Piesa();
        Piesa(const char[], const int);
        Piesa(const Piesa &);
        Piesa & operator=(const Piesa &);
        friend ostream & operator<<(ostream &, Piesa &);
        void afisare(ostream &);
        int getPret() const;
};

class modul_hardware: virtual public Interface
{
    protected:
        vector<Piesa> vec;
        int nr_piese;
        int pm;
        int nr_ore;
    public:
        modul_hardware();
        modul_hardware(vector<Piesa>, const int, const int, const int);
        modul_hardware(const modul_hardware &);
        modul_hardware & operator=(const modul_hardware &);
        void afisare(ostream &);
        int getPret() const;
};

#endif
