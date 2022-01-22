#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Student{
    private:
        int id;
        char *nume;
        char gr_serie[6];
        int note_sem_1[6];
    public:
        void init();
        void afisare() const;
        void modificare(const char[]);
        void modificare(const Student &);
        void modificare(int, int);
        void sortare(Student *, int);
};

int id0;

void Student::init()
{
    id= id0;
    id0++;
    char n[30];
    cin.get();
    cin.getline(n, 30);
    nume= strdup(n);
    fflush(stdin);
    cin>>gr_serie;
    fflush(stdin);
    for(int i=0;i<6;i++)
        cin>>note_sem_1[i];
}

void Student::afisare() const
{
    cout<<"Id: "<<id<<'\n';
    cout<<"Nume: "<<nume<<'\n';
    cout<<"Grupa: "<<gr_serie<<'\n';
    cout<<"Note: ";
    for(int i=0;i<6;i++) cout<<note_sem_1[i]<<" ";
    cout<<"\n\n";
}

void Student::modificare(const char ch[])
{
    strcpy(gr_serie, ch);
}

void Student::modificare(const Student & s)
{
    id= s.id;
    strcpy(nume, s.nume);
    strcpy(gr_serie, s.gr_serie);
    for(int i=0;i<6;i++)
        note_sem_1[i]= s.note_sem_1[i];
}

void Student::modificare(int ii, int val)
{
    note_sem_1[ii]= val;
}

void Student::sortare(Student *s, int n)
{
    int *v= new int[n];
    int k=0;
    float sum;
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=0;j<6;j++) sum= sum + s[i].note_sem_1[k];
        v[k]= sum/6;
        k++;
    }
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(v[i]<v[j])
            {
                swap(v[i],v[j]);
                swap(s[i],s[j]);
            }
}

int main()
{
    int n;
    cout<<"Cati studenti?\n"; cin>>n;
    Student *st= new Student[n];
    fflush(stdin);
    for(int i=0;i<n;i++)
        st[i].init();
    for(int i=0;i<n;i++)
         st[i].afisare();
    st[0].modificare("311AB");
    st[0].afisare();
    Student p;
    p.init();
    st[1].modificare(p);
    st[1].afisare();
    st->sortare(st, n);
    for(int i=0;i<n;i++)
        st[i].afisare();
    return 0;
}
