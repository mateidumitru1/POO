#include "Teren.h"
#include "Imobil.h"

int main()
{
    /*
    int n;
    cout << "INTRODU N-UL: ";
    cin>>n;
    cout << endl;
    char car;
    Proprietate **v= new Proprietate*[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Imobil, teren sau proprietate?(i/t/p)\n";
        cin>>car;
        if(car == 'i')
        {
            Imobil im;
            cin>>im;
            cout << im;
            cout << "\n\n\n\n";
            v[i] = new Imobil(im); //aici
            // cout << "\nAfis imobil de ["<<i<<"]"<<endl;
            // v[i]->afisare(std::cout);
        }
        else if(car == 't')
        {
            Teren t;
            cin>>t;
            v[i]= new Teren(t);
        }
        else if(car == 'p')
        {
            Proprietate p;
            cin>>p;
            v[i]= new Proprietate(p);
        }
    }
    
    // (*v)->sortare(v,n);
    cout << "\nAfisare\n";
    for(int i=0;i<n;i++) cout<< *v[i];
    for(int i=0;i<n;i++)
        if(v[i]->getvaloare() > 10000) cout<<v[i];
    return 0;
    */
   int n = 3;
   Proprietate **v = new Proprietate*[n];
   Proprietate a("anc", 122);
   Imobil b(12, "test", a);
//    b.pseudoAfisare();
   v[1] = new Proprietate("abcde", 100000);
//    v[0]->pseudoAfisare();
   v[2] = new Imobil(12, "avc", a);
   v[0] = new Teren(2333, 2444, a);
   
//    (*v)->sortare(v,n);
    // sort(v, v+n, myCompare);
    cout << "\nAfisare\n";
    for (int i = 0; i < n; i++)
        v[i]->pseudoAfisare();
        cout << "\nCu valori > 10000: \n";
    for(int i=0;i<n;i++)
        if(v[i]->getvaloare() > 10000) v[i]->pseudoAfisare();
    return 0;
}
