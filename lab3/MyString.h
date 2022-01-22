#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef string
#define string

class MyString{
    private:
        char *buf;
        int l;
    public:
        MyString();
        MyString(char *);
        MyString(const MyString &);
        MyString & operator=(const MyString &);
        ~MyString();
        void citire();
        void afisare() const;
        friend const MyString operator+(const MyString&, const MyString&);
        MyString& operator+=(const MyString&);
        friend bool operator==(const MyString&, const MyString&);
        friend bool operator!=(const MyString&, const MyString&);
        int lookFor(char);
};

#endif
