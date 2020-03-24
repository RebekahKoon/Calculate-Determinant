/************************************************************************
** Program name: lab1
** Author:       Rebekah Koon
** Date:         6/24/19
** Description:  Source file for void function readMatrix, which is used 
**               to fill a matrix with integers inputted by the user.
************************************************************************/

#include "isValid.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using std::atoi;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

/************************************************************************
** Description: Void function readMatrix takes a pointer to a 2D array
**              representing a matrix and the size of the matrix as 
**              parameters and prompts the user to enter integers for a 
**              matrix. Calls isValid to determine if input is valid. If 
**              it is not valid, prompts the user to reenter an integer.
**              If it is valid, fills the matrix with the inputted value.
************************************************************************/
void readMatrix(int **arr, int sizeMatrix)
{
    string matrixValueStr;
    bool validInput;
    int matrixValueInt;
    int inputAmount = sizeMatrix * sizeMatrix;

    cout << endl << "Enter " << inputAmount 
         << " numbers for the matrix." << endl;

    //Inputting numbers for the matrix
    for (int i = 0; i < sizeMatrix; i++)
    {
        for (int j = 0; j < sizeMatrix; j++)
        {
            //Keeping track of current row/column of matrix
            int currentRow = i + 1;
            int currentCol = j + 1;

            cout << "Enter number for row " << currentRow
                 << " column " << currentCol << ": ";
            getline(cin, matrixValueStr);

            //Making sure that the value is valid
            validInput = isValid(matrixValueStr);

            //Reenter value for matrix if not an integer
            while (!validInput || matrixValueStr.empty())
            {
                cout << endl << "Please only type in an integer." << endl;

                cout << "Enter number for row " << currentRow
                     << " column " << currentCol << ": ";
                getline(cin, matrixValueStr);

                validInput = isValid(matrixValueStr);
            }

            //Changing string value into integer so determinant can be found
            matrixValueInt = atoi(matrixValueStr.c_str());

            arr[i][j] = matrixValueInt;
        }
    }
}