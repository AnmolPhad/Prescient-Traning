#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    cout << fixed << setprecision(2);
    float radius;
    float area;
    float circumference;

    cout << "Enter radius : ";
    cin >> radius;
   
     // area of cirlce 
     area = 3.14 * radius * radius;
     cout << "\nArea of circle is : " << area << endl;

     //circumference of circle 
     circumference = 2 * 3.14 * radius * radius;
     cout << "Circumference of cirlce is : " << circumference;


}