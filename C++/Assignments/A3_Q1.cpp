#include <iostream>
using namespace std;

int factorial(int n);
int main(void)
{
    int factNo;
    cout << "Enter a number ";
   cin >> factNo;

   cout << factorial(factNo);
}

int factorial(int n)
{
    int fact=1;


    for(int i =2 ; i <= n ; i++)
    {
      fact *= i;
    }
    return fact;
}

