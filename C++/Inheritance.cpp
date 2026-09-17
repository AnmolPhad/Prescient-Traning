#include <iostream>
#include <string>


using namespace std;


class Person {

protected:
    string name;
    int age;

public :
    Person()
    {
        cout << "Base Constructor ";
        name = "";
        age = 0;
    }

    Person(string n, int a){
        cout << "\nParameterized Constructor of base class";
        name = n;
        age = a;
    }

   virtual void display(){
        cout << "\nName: " << name << endl;
        cout << "Age: " << age << endl;
    }
    
};

class Student : public Person
{
    int roll;
public :
    Student() 
    {
        cout << "\nDerived Constructor";
        roll = 0;
    }

    Student(string n, int a, int r) : Person(n, a)
    {
        cout << "\nParameterized Constructor of derived class";
        roll = r;
    }
    void display() override {
        Person::display();
        cout << "\nRoll: " << roll << endl;
    }

};

int main(void){
Person* p1 =new  Student("Rahul", 20, 101);

p1->display();
cout << typeid(p1).name();

Student* s1 =dynamic_cast<Student*>(p1);

s1->display();

return 0;

}