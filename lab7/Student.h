#include "Persoana.h"

#ifndef student
#define student

class Student: virtual public Persoana
{
    int id_student;
    int n;
    int *note;
    public:
        Student();
        Student(const int, const int, const int *);
        Student(const Student &);
        ~Student();
        Student & operator=(const Student &);
        istream & citire(istream &);
        ostream & afisare(ostream &);
        void afisare();
        friend istream & operator>>(istream &, Student &);
        friend ostream & operator<<(ostream &, Student &);
        int getVenit(); // 700 sau 0
};

#endif
