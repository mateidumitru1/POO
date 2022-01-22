#include "Angajat.h"
#include "Student.h"


using namespace std;

#ifndef student_angajat
#define student_angajat

class Student_Angajat: public Student, public Angajat{
    public:
        Student_Angajat();
        Student_Angajat(const Angajat &, const Student &);
        Student_Angajat(const int, const int, const int, const int, const int *);
        Student_Angajat(const Student_Angajat &);
        ~Student_Angajat();
        Student_Angajat & operator=(const Student_Angajat &);
        istream & citire(istream &);
        ostream & afisare(ostream &);
        void afisare();
        friend istream & operator>>(istream &, Student_Angajat &);
        friend ostream & operator<<(ostream &, Student_Angajat &);
        int getVenit(); // salariu + 700 sau 0
};

#endif
