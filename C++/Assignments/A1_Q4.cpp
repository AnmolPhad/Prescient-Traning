#include <iostream>

using namespace std;

int main(void)
{
    int number ;
    cout << "Enter a positive number : " ;
    cin >> number;
    int reverse = 0;
    while(number != 0)
    {
     int n = number %10;
     reverse = reverse *10 + n;
     number /= 10;
    }
    cout << "Reverse number : " << reverse;
}