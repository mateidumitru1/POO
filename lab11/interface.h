#ifndef INTERFACE
#define INTERFACE

using namespace std;

class Interface
{
    public:
        virtual void afisare(ostream &) = 0;
        virtual int getPret() const = 0;
};

#endif
