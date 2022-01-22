#include "Angajat.h"

int main()
{
    Angajat *a;
    int n, sal;
    char nn[30], CNP[14];
    cout<<"Cati angajati?\n"; cin>>n;
    a= new Angajat[n];
    for(int i=0;i<n;i++)
    {
        cin.get();
        cout<<"\nNume: "; cin.get(nn, 30);
        cin.get();
        cout<<"CNP: ";    cin.get(CNP,14);
        cin.get();
        cout<<"Salariu "; cin>>sal;
        Angajat p(nn, CNP, sal);
        a[i].modificare(p);
    }
    cout<<'\n';
    // a->sortare(a,n);  Nu functioneaza cum trebuie
    for(int i=0;i<n;i++)
        a[i].afisare();

    Angajat p("Dan", "1234567890123", 12345);
    a[0].modificare(p);
    for(int i=0;i<n;i++) a[i].afisare();

    int nr=0;
    for(int i=0;i<n;i++)
        if( a[i].eFemeie() ) nr++;
    cout<<"Sunt "<< nr <<" femei si "<< n-nr <<" barbati.\n";

    
    cout<<"Angajatii cu salariu mai mare de 3000 de lei sunt: \n";
    for(int i=0;i<n;i++)
        if( a[i].getSalariu() > 3000 ) a[i].afisare();

    return 0;
}
