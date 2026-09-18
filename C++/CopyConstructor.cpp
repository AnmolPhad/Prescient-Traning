#include <iostream>
using namespace std;

class Complex{
  int real ;
  int img;
//   int* ptr = new int(30) ;
  

  public :
  Complex()
  {

  }
    Complex(int r , int i)
    {
        real = r;
        img = i;
        

    }

    void display()
    {
        cout << real << " + " << img << "i" << endl;
        // cout << *ptr;
    }
    Complex(const Complex &other)
    {
        cout << "Copy constructor called";
        this->real = other.real;
        this->img = other.img ;
        // deep copy
        // this->ptr= new int(*other.ptr);
        cout << endl;
    }

   Complex operator+(const Complex &other)
   {
       Complex temp;

       temp.real = real + other.real;
       temp.img = img + other.img;
       return temp;

   }
    
};

int main(void)
{
    Complex c1 = Complex(10 , 20);
    // c1.dispaly();
    
     cout << endl;
    Complex c2 = c1;
     Complex c3 = c1.operator+(c2);
    c3.display();
    
    
  

   
   

   
}