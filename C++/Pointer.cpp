#include <iostream>
using namespace std;

class Base{
    int num1;
    public :
    Base() : num1(10)
    {

    }

    virtual void dispaly()
    {
        cout << num1 << endl;
    }
};

class Derived : public Base{
    int num2;
    public :
    Derived() : num2(20)
    {

    }
    void dispaly() override
    {
        Base::dispaly();
        cout << num2 << endl;
    }
};

int main(void)
{
    Base *p =new Derived();

    Base &r = *p;

    p->dispaly();
    r.dispaly();

    return 0;
}