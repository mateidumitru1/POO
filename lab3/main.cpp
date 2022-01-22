#include "MyString.h"

int main()
{
    MyString a;
    a.citire();
    
    char c[10];
    strcpy(c,"abc");
    
    MyString b;
    
    b= a;
    b.afisare();
    MyString p(c);
    p.afisare();

    MyString cc= p+a;
    cc.afisare();

    
    a+=p;
    a.afisare();

    if ( a == b ) cout<<"egal\n";
    if ( a != b ) cout<<"diferit\n";

    cout<<a.lookFor('1')<<"\n";

    return 0;
}