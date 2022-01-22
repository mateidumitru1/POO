#ifndef PRODUS_MIXT
#define PRODUS_MIXT

#include <iostream>
#include <vector>
#include "modul_hardware.h"
#include "produs_software.h"

using namespace std;

class produs_mixt: public modul_hardware, virtual public Interface
{
    produs_software ps;
    vector<string> functionalitati;
    int nr_functionalitati;
    public:
        produs_mixt();
        produs_mixt(const produs_software &, vector<string>, const int, const modul_hardware &);
        produs_mixt(const int, vector<string>, const int, vector<Piesa>, const int, const int, const int);
        produs_mixt(const produs_mixt &);
        produs_mixt & operator=(const produs_mixt &);
        void afisare(ostream &);
        int getPret() const;
};

#endif
