#include "Student_Angajat.h"

void sortare(Persoana **v, int n)
{
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if( v[i]->getVenit() > v[j]->getVenit() )
                swap(v[i], v[j]);
}

int main()
{
    int n = 3;
    int *vec= new int[n];
    vec[0] = 10; vec[1] = 10; vec[2] = 6;
    Student s(123, 3, vec);
    Angajat a(432, 2000);
    Persoana **v= new Persoana*[3];
    v[0] = new Student_Angajat(a, s);
    v[1] = new Student(1234, 3, vec);
    v[2] = new Angajat(432, 2000);
    sortare(v, n);
    for(int i = 0; i < 3; i++)
    {
        v[i]->afisare();
        cout << endl << "Venit: " << v[i]->getVenit() << "\n";
    }
    
    return 0;
}