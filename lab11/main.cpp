#include "produs_mixt.h"
#include <fstream>

int calculeazaSuma(vector<Interface*> v)
{
    int suma = 0;
    for(int i = 0; i < v.size(); i++)
    {
        suma = suma + v[i]->getPret();
    }
    return suma;
}

int main()
{
    vector<Piesa> v(3);
    Piesa a("111111", 40);
    Piesa b("222222", 50);
    Piesa c("333333", 60);
    v[0] = a;
    v[1] = b;
    v[2] = c;
    produs_software ps(60);
    modul_hardware mh(v, 3, 20, 5);
    vector<string> str(2);
    str[0] = "ppppp";
    str[1] = "lllll";
    produs_mixt pm(20, str, 2, v, 3, 20, 5);

    vector<Interface*> vect;

    vect.push_back(new produs_software(ps));
    vect.push_back(new modul_hardware(mh));
    vect.push_back(new produs_mixt(pm));

    ofstream out("date.out");

    cout << "Suma: " << calculeazaSuma(vect) << "\n";

    for(int i = 0; i < 3; i++)
        vect[i]->afisare(out);

    vect.erase(vect.begin());
    vect.erase(vect.begin());


    vector<Interface *>::iterator i = vect.begin();

    vect.insert(i, new produs_software(ps));
    
    return 0;
}
