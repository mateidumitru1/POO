#include <assert.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template <typename T>
class vector
{
   int dim;
   T *buf;

public:
   vector();
   vector(int, T *);
   vector(const vector &);
   vector & operator=(const vector &);
   ~vector();
   T & operator[](int i);
   int getDim();

   friend ostream & operator<<(ostream &dev, vector &v)
   {
      dev << "Vector: " << endl;
      dev << "Nr Elem: " << v.dim << endl;
      if (v.buf != NULL)
         for (int i = 0; i < v.dim; i++)
         {
            dev << v.buf[i]; // am nevoie de op<< pt T
         }
      dev << endl;
      return dev;
   }

   void addElem(int, T&  ); // - adauga element T pe pozitia i - cu realocare
   void removeElem(int  ); // - sterge elementul de pe pozitia i cu realocare
   void sortare(); //ordoneaza crescator elementele din buf; in T avem nevoie de op<
};

template <typename T>
vector<T>::vector()
{
   dim = 0;
   buf = NULL;
}

template <typename T>
vector<T>::vector(int d, T *b)
{
   dim = d;
   if (b == NULL)
      buf = NULL;
   else
   {
      buf = new T[dim]; // constr fara param in T
      for (int i = 0; i < dim; i++)
         buf[i] = b[i]; // op= in T
   }
}

template <typename T>
vector<T>::vector(const vector<T> &v)
{
   dim = v.dim;
   if (v.buf == NULL)
      buf = NULL;
   else
   {
      buf = new T[dim]; // constr fara param in T
      for (int i = 0; i < dim; i++)
         buf[i] = v.buf[i]; // op= in T
   }
}

template <typename T>
vector<T>::~vector()
{
   if (buf != NULL)
      delete[] buf; // destr in T
}

template <typename T>
vector<T> &vector<T>::operator=(const vector &v)
{
   dim = v.dim;
   if (buf != NULL)
      delete[] buf; // destr in T
   if (v.buf == NULL)
      buf = NULL;
   else
   {
      buf = new T[dim]; // constr fara param in T
      for (int i = 0; i < dim; i++)
         buf[i] = v.buf[i]; // op= in T
   }
   return *this;
}

template <typename T>
T &vector<T>::operator[](int i)
{
   assert((i > -1 && i < dim));
   return buf[i]; // constr de copiere in T
}

template <typename T>
int vector<T>::getDim()
{
   return dim;
}

template <typename T>
void vector<T>::addElem(int p, T & v)
{
   dim++;
   T * copie = new T[dim];
   int i = 0, j = 0;
   while( i < dim )
   {
      if( i == p ) copie[i] = v;
      else 
      {
         copie[i] = buf[j];
         j++;
      }
      i++;
   }
   delete[] buf;
   buf = new T[dim];
   for(int i = 0; i < dim; i++)
      buf[i] = copie[i];
   delete[] copie;
}

template <typename T>
void vector<T>::removeElem(int p)
{
   T * copie = new T[dim - 1];
   int i = 0, j = 0;
   while( i < dim )
   {
      if( i == p ) j--;
      else copie[j] = buf[i];
      i++;
      j++;
   }
   delete[] buf;
   dim--;
   buf = new T[dim];
   for(int i = 0; i < dim; i++)
      buf[i] = copie[i];
   delete[] copie;
}

template <typename T>
void vector<T>::sortare()
{
   for(int i = 0; i < dim-1; i++)
      for(int j = i + 1; j < dim; j++)
         if( buf[i] > buf[j] ) swap(buf[i], buf[j]);
}

class complex
{
   double re, im;

public:
   complex(double r = 0, double i = 0) : re(r), im(i){}

   friend ostream &operator<<(ostream &d, complex x)
   {

      d << x.re << " " << x.im << "j\n" ;
      return d;
   }
   friend bool operator>(const complex c1, const complex c2)
   {
      if(c1.re > c2.re) return true;
      else if (c1.re == c2.re && c1.im > c2.im) return true;
      return false;
   }
};

template <typename X, typename Y>
class pereche
{
   X elem1;
   Y elem2;
   public:
      pereche(){}
      pereche(const X & e1, const Y & e2)
      {
         elem1 = e1;
         elem2 = e2;
      }
      pereche & operator=(const pereche & p1)
      {
         elem1 = p1.elem1;
         elem2 = p1.elem2;
         return *this;
      }
      friend ostream & operator<<(ostream &d, const pereche & x)
      {
         d << x.elem1 << " = " << x.elem2 << endl;
         return d;
      }
      friend bool operator>(const pereche & p1, const pereche & p2)
      {
         if(p1.elem1 > p2.elem1) return true;
         else if(p1.elem1 == p2.elem1 && p1.elem2 > p2.elem2) return true;
         else return false;
      }
};



class Proprietate{
    protected:
        char cod[6];
        double valoare;
    public:
        Proprietate();
        Proprietate(char const *, double);
        Proprietate(const Proprietate &);
        Proprietate & operator=(const Proprietate &);
        istream & citire(istream &);
        ostream & afisare(ostream &);
        friend istream & operator>>(istream &, Proprietate &);
        friend ostream & operator<<(ostream &, Proprietate &);
        double getvenit();
        void sortare(Proprietate **, int);
        double getvaloare();
        virtual void pseudoAfisare();
        friend bool operator>(const Proprietate & p1, const Proprietate & p2);
};


Proprietate::Proprietate()
{
    cod[0]= '\0';
    valoare= 0;
}

Proprietate::Proprietate(char const *c, double n): valoare(n)
{
    strcpy(cod, c);
}

Proprietate::Proprietate(const Proprietate & p): valoare(p.valoare)
{
    strcpy(cod, p.cod);
}

Proprietate & Proprietate::operator=(const Proprietate & p)
{
    valoare= p.valoare;
    if( cod[0] != '\0' ) cod[0]= '\0';
    strcpy(cod, p.cod);
    return *this;
}

istream & Proprietate::citire(istream & a)
{
    cout<<"Cod: "; a>>cod;
    cout<<"Valoare: "; a>>valoare;
    return a;
}

istream & operator>>(istream & a, Proprietate & p)
{
    return p.citire(a);
}

ostream & Proprietate::afisare(ostream & a)
{
    cout<<"\nCod: ";
    a<<cod;
    cout<<"\nValoare: ";
    a<<valoare;
    cout<<"\n";
    return a;
}

ostream & operator<<(ostream & a, Proprietate & p)
{
    return p.afisare(a);
}

double Proprietate::getvenit()
{
    return 0;
}

void Proprietate::sortare(Proprietate **v, int n)
{

    cout << "nope";
}

double Proprietate::getvaloare()
{
    return valoare;
}

void Proprietate::pseudoAfisare()
{
    cout << "\nProprietate\n";
    cout << "Cod: " << cod << endl;
    cout << "Valoare: " << valoare << endl;
}

bool operator>(const Proprietate & p1, const Proprietate & p2)
{
   if( p1.valoare > p2.valoare ) return true;
   return false;
}


int main()
{
   /*      COMPLEX      */
   complex *b = new complex[2];
   b[0] = complex(5, 6);
   b[1] = complex(9, 2);
   vector<complex> v(2, b);
   cout << v;

   cout << v[0];

   v[1] = complex(5, 5);
   cout << v;

   vector<complex> v1(v);
   cout << v1;

   v = v1;
   cout << v;

   v.sortare();

   cout << v;

   /*       INT         */

   // int *a = new int[2];
   // a[0] = 1;
   // a[1] = 2;
   // vector<int> v(2, a);

   // cout << v;

   // cout << v[0] << endl;

   // v[1] = int(1);
   // cout << v;
   // vector<int> v1(v);

   // cout << v;
   // v = v1;

   // cout << v;

   /*       STRING      */

   // string *c = new string[2];
   // c[1] = "avion";
   // c[0] = "camion";
   // vector<string> v(2, c);

   // cout << v;

   // cout << v[0] << endl << endl;

   // v[1] = "oof";
   // cout << v;
   // vector<string> v1(v);

   // cout << v;
   // v = v1;

   // cout << v;

   // string s = "alb";


   // v.addElem(1, s);

   // cout << v;

   // v.removeElem(2);

   // cout << v;

   // v.sortare();

   // cout << v;

   /*     PERECHE     */


   // pereche <string, string> * p = new pereche<string, string>[3];
   
   // pereche <string, string> aux("caine", "dog");
   // pereche <string, string> aux1("pisica", "cat");
   // pereche <string, string> aux2("vaca", "cow");

   // p[0] = aux;
   // p[1] = aux1;
   // p[2] = aux2;

   // vector < pereche <string,string> > v(3, p);

   // cout << v;
   
   // pereche <string, string> aux3("maimuta", "monkey");

   // v.addElem(3, aux3);

   // cout << v;

   // v.removeElem(3);

   // cout << v;

   // v.addElem(0, aux3);

   // v.sortare();

   // cout << v;


   /*     PROPRIETATE      */

   // Proprietate aux1("1234", 3000);
   // Proprietate aux2("5123", 2000);
   // Proprietate aux3("7654", 1000);
   // Proprietate aux4("9875", 7000);

   // Proprietate *p = new Proprietate[3];

   // p[0] = aux1;
   // p[1] = aux2;
   // p[2] = aux3;

   // vector <Proprietate> v(3, p);

   // cout << v;

   // v.addElem(0, aux4);

   // cout << v;

   // v.sortare();

   // cout << v;


   return 0;
}
