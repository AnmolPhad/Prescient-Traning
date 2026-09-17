#include <iostream>
using namespace std;

class Complex{
  int real ;
  int img;

  public :
    Complex(int r , int i)
    {
        real = r;
        img = i;
    }

    void dispaly()
    {
        cout << real << " + " << img << "i" << endl;
    }
    Complex(const Complex &other)
    {
        cout << "Copy constructor called";
        this->real = other.real;
        this->img = other.real ;
        cout << endl;
    }
};

int main(void)
{
    Complex c1 = Complex(10 , 20);
    c1.dispaly();
    cout << &c1;
     cout << endl;
    Complex c2 = c1;
    c2.dispaly();
    cout << &c2;
}