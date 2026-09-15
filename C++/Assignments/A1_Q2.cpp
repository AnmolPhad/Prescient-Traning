#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(void)
{
    string name ;
    int age;
    float height;
    char gender;

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter age : " ;   
    cin >> age;
    cout << fixed << setprecision(2);
    cout << "Enter height: ";
    cin >> height;

    cout << "Enter Gender(F or M):";
    cin >> gender;

    cout << "Name : " << name << endl ;
    cout << "Age : " << age << endl;
    cout << "Gender : " << gender << endl;
    cout << "Height : " << height << endl ;




    return 0;
}

