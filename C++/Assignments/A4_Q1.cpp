#include <iostream>
using namespace std;

int maxNumber(int arr[] , int size);
int minNumber(int arr[] , int size);
float average(int arr[] , int size);
void findNum(int arr[] , int size , int num);
int main(void)
{
    int *arr = new int[10]();

    cout << "Enter 10 numbers: ";

    for(int i = 0 ; i < 10 ; i++)
    {
        cin >> arr[i] ;
    }

    cout << "Array Elements : ";
    for(int i = 0 ; i < 10 ; i++)
    {
        cout << arr[i] << " ";
    }
   
    cout << "\nMax number is : " << maxNumber(arr , 10);
    cout << "\nMin number is : " << minNumber(arr , 10);
    cout << "\nAverage is : " << average(arr , 10);
    cout << "\nEnter a numbber to find : ";
    int num ;
    cin >> num;
    
    findNum(arr , 10 , num);

    delete[] arr;
    return 0;
} 

void findNum(int arr[] , int size , int num)
{
   for(int i = 0 ; i < size ; i++)
   {
    if(arr[i] == num){
       cout << "Number found at index : " <<  i ;
       return ;
    }
    
   }
  cout << "Number not found";
}

float average(int arr[] , int size)
{ 
    float avg = 0;
    for(int i=0 ; i < size ; i++ )
    {
        avg += arr[i];
    }
    return  avg / size;
   
}

int minNumber(int arr[] , int size)
{

    int min = arr[0];
    for(int i = 1 ; i < size ; i++)
    {
      if(min > arr[i])
        min = arr[i];
    }
    return min;
}

int maxNumber(int arr[] , int size)
{
   
    int max = arr[0];
    for(int i = 1 ; i < size ; i++)
    {
      if(max < arr[i])
        max = arr[i];
    }
    return max;
}