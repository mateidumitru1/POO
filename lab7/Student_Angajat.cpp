#include "Student_Angajat.h"

Student_Angajat::Student_Angajat(){}

Student_Angajat::Student_Angajat(const Angajat & a, const Student & s): Student(s), Angajat(a){}

Student_Angajat::Student_Angajat(const int id1, const int s, const int id2, const int nr, const int * v): Angajat(id1, s), Student(id2, nr, v){}

Student_Angajat::Student_Angajat(const Student_Angajat & sa): Student(sa), Angajat(sa){}

Student_Angajat::~Student_Angajat(){}

Student_Angajat & Student_Angajat::operator=(const Student_Angajat & sa)
{
    Angajat::operator=(sa);
    Student::operator=(sa);
    return *this;
}

istream & Student_Angajat::citire(istream & a)
{
    Angajat::citire(a);
    Student::citire(a);
    return a;
}

istream & operator>>(istream & a, Student_Angajat & sa)
{
    return sa.citire(a);
}

ostream & Student_Angajat::afisare(ostream & a)
{
    Angajat::afisare(a);
    Student::afisare(a);
    return a;
}

ostream & operator<<(ostream & a, Student_Angajat & sa)
{
    return sa.afisare(a);
}

void Student_Angajat::afisare()
{
    Angajat::afisare();
    Student::afisare();
}

int Student_Angajat::getVenit()
{
    return Student::getVenit() + Angajat::getVenit();
}
