#include<iostream> 
using namespace std; 

//custom exception class

class ArathmaticException 
{
    string  msg ;
    public :
    ArathmaticException(string msg) 
    {
        this->msg = msg;
    }
    string getMesage()
    {
        return msg;
    }
};

void acceptRecord(string msg , int &number)
{
    cout<<msg; 
    cin>>number; 
}
int main()
{
    cout<<"Open the connection "<<endl;
    
    int num1; 
    ::acceptRecord("num1  : ",num1); 
    
    int num2; 
    ::acceptRecord("num2 : ",num2); 

    try
    {
        if(num2==0)
        {
           ArathmaticException ex("Devide by zero");
           throw ex;
        }
        else 
        {
            int res = num1 / num2; 
            cout<<"result : "<<res<<endl; 
        }

    }
    catch(int ex)
    {
        cout<<"int : exception occured"<<endl; 
    }
    catch(double ex)
    {
        cout<<"double : exception occured"<<endl; 
    }
    catch(ArathmaticException e)
    {
          cout << e.getMesage() << endl ;
    }
    cout<<"Close the connection "<<endl;
    return 0;
}
