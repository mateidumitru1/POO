#include "MyString.h"

MyString::MyString()
{
    buf= NULL;
    l= 0;
}

MyString::MyString(char *p)
{
    buf= strdup(p);
    l= strlen(p);
}

MyString::MyString(const MyString & p)
{
    buf= strdup(p.buf);
    l= p.l;
}

MyString & MyString::operator=(const MyString & p)
{
    l= p.l;
    if(buf != NULL) delete[] buf;
    buf= strdup(p.buf);
    return *this;
}

MyString::~MyString()
{
    if(buf != NULL) delete[] buf;
}

void MyString::citire()
{
    if(buf != NULL) delete[] buf;
    cout<<"Introduceti string-ul pe care doriti sa il stocati: ";
    char p[30];
    cin.get(p, 30);
    cin.get();
    buf= strdup(p);
    l= strlen(p);
}

void MyString::afisare() const
{
    cout<<buf<<"\n";
}

const MyString operator+(const MyString& p1, const MyString& p2)
{
    MyString n;
    n.buf= new char[p1.l + p2.l + 1];
    strcpy(n.buf, p1.buf);
    strcat(n.buf, p2.buf);
    n.l= p1.l + p2.l + 1;
    return n;
}

MyString & MyString::operator+=(const MyString & p)
{
    strcat(buf, p.buf);
    l= l + p.l;
    return *this;
}

bool operator==(const MyString& p1, const MyString& p2)
{
    if( strcmp(p1.buf, p2.buf) == 0 ) return true;
    return false;
}

bool operator!=(const MyString& p1, const MyString& p2)
{
    if( strcmp(p1.buf, p2.buf) != 0 ) return true;
    return false;
}

int MyString::lookFor(char p)
{
    int nr= 0;
    for(int i=0;i<strlen(buf);i++)
        if(buf[i] == p) nr++;
    return nr;
}
