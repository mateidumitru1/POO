#include "Ansamblu.h"

void sortare(Interfata **in, int n)
{
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if( in[i]->getPret() < in[j]->getPret() )
                swap(in[i], in[j]);
}

int main()
{
    Piesa_A a(120, "123", 2);
    Piesa_B b(222, "567", "rosu");
    Piesa_B c(333, "654", "negru");
    Piesa_B v[2];
    v[0] = b;
    v[1] = c;
    string *s = new string[2];
    s[0] = "ananas";
    s[1] = "cartof";
    Ansamblu ap(a, v, 2, s);
    Ansamblu cp = ap;
    Ansamblu bp(cp);
    bp = ap;
    
    Interfata **i = new Interfata*[4];

    i[0] = new Piesa_A(a);
    i[1] = new Piesa_B(b);
    i[2] = new Piesa_B(c);
    i[3] = new Ansamblu(ap);

    // for(int ii = 0; ii < 4; ii++)
    //     i[ii]->afisare();

    sortare(i, 4);

    ofstream out("date.out");

    for(int ii = 0; ii < 4; ii++)
    {
        i[ii]->afisareFisier(out);
        out << "\n";
    }


    return 0;
}