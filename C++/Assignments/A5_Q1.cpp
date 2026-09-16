#include <iostream>
using namespace std;

 long factorial(int n)
{
   if (n <= 1) {
        return n;
    }

    return n * factorial(n - 1);
}

int fibonacciRecursive(int n) {
    
    if (n <= 1) {
        return n;
    }
   
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

void fibonacciIterative(int n)
{
    int a = 0;
    int b = 1;

    for(int i = 0; i < n; i++)
    {
        cout << a << " ";

        int temp = a + b;
        a = b;
        b = temp;
    }
}

int main(void)
{

      int n;
    int a, b;

    cout << "Enter a number for Factorial and Fibonacci: ";
    cin >> n;

  

    cout << "\n--- Results ---\n";

    // Factorial
    cout << "Factorial of " << n << " = "
         << factorial(n) << endl;

    // Fibonacci Recursive
    cout << "Fibonacci (Recursive): ";

    for(int i = 0; i < n; i++)
    {
        cout << fibonacciRecursive(i) << " ";
    }

    cout << endl;

    // Fibonacci Iterative
    cout << "Fibonacci (Iterative): ";
    fibonacciIterative(n);

    cout << endl;


    return 0;
}