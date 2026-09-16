#include <iostream>
using namespace std;

int main(void)
{
    int marks;
    cout << "Enter a number 0 to 100";
    cin >> marks;

    if(marks >= 90)
    {
        cout << "A Grade";
    }
    else if(marks >= 80 && marks < 90)
    {
        cout << "B grade";
    }
    else if(marks >= 70 && marks < 80){
        cout << "C Grade";

    }
    else if(marks >= 60 && marks < 70)
    {
        cout << "D Grade";
    }
    else 
    {
        cout << "Fail";
    }
}