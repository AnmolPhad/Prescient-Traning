#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    fstream file("user.txt" , ios::app | ios::in);
    string data;

    if(file.is_open())
    {
    
    while(getline(file , data))
      {
       cout << data << endl;
      }
    }
    else 
    {
        cout << "file is not open";
    }
    file.close();

}


//read from file
int main2(void)
{
    ifstream file("user.txt");
   string data;

   while(getline(file , data))
   {
       cout << data << endl;
   }
file.close();
return 0;
}


// write into file
int main1(void)
{
    ofstream file("user.txt");

    string name;
    int age;
    string city;

    cout << "Enter name: ";
    getline(cin , name);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();
    cout <<"Enter city: ";
    getline(cin , city);

    file << "Name: " << name << endl;
    file << "Age: " << age << endl;
    file << "City: " << city << endl;

    file.close();



    return 0;
}