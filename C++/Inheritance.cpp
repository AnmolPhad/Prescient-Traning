#include <iostream>
#include <string>


using namespace std;


class person {

    string name;
    int age;


    person()
    {
        cout << "Base Constructor";
        name = "";
        age = 0;
    }
    
};