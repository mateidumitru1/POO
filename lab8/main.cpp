#include "functii.h"

int main()
{
    ifstream f("date.in");
    int n = CateLinii(f);
    cout << n << endl << endl;
    f.clear();
    f.seekg(0);
    string * v = CreeazaVector(f, n);
    for(int i = 0; i < n; i++)
        cout << v[i] << endl;
    CreeazaFisiere(v, n);
    ExtrageDateNastere(v, n);
    SchimbaCuXY(n);
    cout << "\nNumarul de persoane din Bucuresti este: " << NrPersoaneBucuresti(v, n) << endl;
    return 0;
}