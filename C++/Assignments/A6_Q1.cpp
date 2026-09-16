#include <iostream>
using namespace std;

void inputMatrix(int **matrix , int row , int col )
{
   for(int i = 0 ; i < row ; i++)
  {
    for(int j = 0 ; j < col ; j++)
    {
       matrix[i][j] =  i + j;;
    }
  }
}

void displayMatrix(int **matrix, int row , int col )
{
   for(int i = 0 ; i < row ; i++)
  {
    for(int j = 0 ; j < col ; j++)
    {
        cout << matrix[i][j] << "  ";
    }
    cout << endl;
  }
}


int main(void)
{
    int row , col ;
    cout << "Enter row and col size : ";
    cin >> row >> col;

    // 2d array - dynamic memory allocation
  int **matrix1 = new int*[row];
  int **matrix2 = new int*[row];

  for(int i = 0; i < row; i++)
    {
        matrix1[i] = new int[col];
        matrix2[i] = new int[col];
    }


  inputMatrix(matrix1 , row , col);
  displayMatrix(matrix1, row , col);

  
                                             

  inputMatrix(matrix2 , row , col);
  displayMatrix(matrix2, row , col);
                                                              







    for(int i = 0; i < row; i++)
    {
        delete[] matrix1[i];
    }

    delete[] matrix1;

    return 0;

  
}