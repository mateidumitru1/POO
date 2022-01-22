#include "functii.h"

int CateLinii(ifstream & f)
{
    int nr = -1;
    char s[14];
    while( !f.eof() )
    {
        f.getline(s, 14, '\n');
        nr++;
    }
    return nr;
}

string * CreeazaVector(ifstream & f, int n)
{
    string * v = new string[n];
    char s[14];
    int i = -1;
    for(int i = 0; i < n; i++)
    {
        f.getline(s, 14, '\n');
        v[i] = s;
    }
    return v;
}

void CreeazaFisiere(string * v, int n)
{
    ofstream femei("femei.out");
    ofstream barbati("barbati.out");
    for(int i = 0; i < n; i++)
       if( v[i].at(0) == '1') barbati << v[i] << endl;
       else femei << v[i] << endl; 
}

void ExtrageDateNastere(string * v, int n)
{
    string * a = new string[n];
    for(int i = 0; i < n; i++)
    {
        a[i] = v[i].substr(1,6);
    }

    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
        {
            if( a[i].substr(0,2) < a[j].substr(0,2) ) swap(a[i], a[j]);
            else if( a[i].substr(0,2) == a[j].substr(0,2) && a[i].substr(2,2) < a[j].substr(2,2) ) swap(a[i], a[j]);
            else if( a[i].substr(0,2) == a[j].substr(0,2) && a[i].substr(2,2) == a[j].substr(2,2) && a[i].substr(4,2) < a[j].substr(4,2) ) swap(a[i], a[j]);
        }
    ofstream date("date_nastere.out");
    for(int i = 0; i < n; i++)
        date << a[i] << endl;
}

void SchimbaCuXY(int n)
{
    ifstream in("date_nastere.out");
    string *v = new string[n];
    for(int i = 0; i < n; i++)
    {
        getline(in, v[i]);
        if(v[i].find("010") < 256) v[i].replace(v[i].find("010"), 3, "XY");
    }
    ofstream out("date_nastere.out");
    for(int i = 0; i < n; i++)
        out << v[i] << endl;
}

int NrPersoaneBucuresti(string * v, int n)
{
    int nr = 0;
    for(int i = 0; i < n; i++)
        if( v[i].substr(7,2) == "41" || v[i].substr(7,2) == "42" || v[i].substr(7,2) == "43" ||
            v[i].substr(7,2) == "44" || v[i].substr(7,2) == "45" || v[i].substr(7,2) == "46" )
            nr++;
    return nr;
}
