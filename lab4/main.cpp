#include "Produs.h"

int main()
{
    // Garantie g(12, "abc");
    // Produs p1(120,"LG",g);
    // Produs p2= p1;
    // Produs p3(p1);
    // cout<<p1<<"\n"<<p2<<"\n"<<p3;
    int nr;
    cout<<"\n\nIntroduceti numarul de produse: "; cin>>nr;
    Produs *n= new Produs[nr];
    for(int i=0;i<nr;i++)
        cin>>n[i];
    // sortare(n,nr);
    // for(int i=0;i<nr;i++)
    //     cout<<n[i];
    // garantie12(n, nr);
    search_service(n,nr,"SerVice");
    return 0;
}