#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef persoana
#define persoana

class Persoana{
    public:
        virtual ~Persoana();
        virtual void afisare() = 0;
        virtual int getVenit() = 0;
};

#endif
