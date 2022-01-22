#include "Student.h"

Student::Student()
{
    id_student = 0;
    n = 0;
    note = NULL;
}

Student::Student(const int id, const int nr, const int * v): id_student(id), n(nr)
{
    note = new int[nr];
    for(int i = 0; i < nr; i++)
        note[i] = v[i];
}

Student::Student(const Student & s): id_student(s.id_student), n(s.n)
{
    note = new int[s.n];
    for(int i = 0; i < s.n; i++)
        note[i] = s.note[i];
}

Student::~Student()
{
    delete[] note;
}

Student & Student::operator=(const Student & s)
{
    if( note != NULL ) note = NULL;
    id_student = s.id_student;
    n = s.n;
    note = new int[s.n];
    for(int i = 0; i < s.n; i++)
        note[i] = s.note[i];
    return *this;
}

istream & Student::citire(istream & a)
{
    cout<<"Id student: "; a >> id_student;
    cout<<"Numar note: "; a >> n;
    cout<<"Note: ";
    note = new int[n];
    for(int i = 0; i < n; i++)
        a >> note[i];
    return a;
}

istream & operator>>(istream & a, Student & s)
{
    return s.citire(a);
}

ostream & Student::afisare(ostream & a)
{
    cout<<"\nId student: "; a << id_student;
    cout<<"\nNumar note: "; a << n;
    cout<<"\nNote: ";
    for(int i = 0; i < n; i++)
        a << note[i] << " ";
    return a;
}

ostream & operator<<(ostream & a, Student & s)
{
    return s.afisare(a);
}

void Student::afisare()
{
    cout<<"\nId student: " << id_student;
    cout<<"\nNumar note: " << n;
    cout<<"\nNote: ";
    for(int i = 0; i < n; i++)
        cout << note[i] << " ";
}

int Student::getVenit()
{
    float s = 0;
    for(int i = 0; i < n; i++)
    {
        if( note[i] < 5 ) return 0;
        s = s + note[i];
    }
    s = s / n;
    if( s > 8.5 ) return 700;
    return 0;
}
