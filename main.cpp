/***********************************************************************
** Program name: lab1
** Author:       Rebekah Koon
** Date:         6/24/19
** Description:  Main function for lab1 that asks the user to create
**               either a 2x2 or 3x3 matrix. The user then enters 
**               integers for the matrix and the determinant is
**               calculated. The matrix and determinant is then printed.
***********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

#include "readMatrix.hpp"
#include "determinant.hpp"
#include "isValid.hpp"

using std::cout;
using std::getline;
using std::cin;
using std::endl;
using std::string;
using std::atoi;
using std::left;
using std::setw;


/************************************************************************
** Description: This program runs by inputting a 2 or 3 to create a 2x2
**              or 3x3 matrix. Calls function isValid to determine if
**              input is valid. If not valid, asks user to reenter input.
**              If valid, dynamically allocates memory for a 2d array and
**              calls readMatrix for the user to input integers into the 
**              matrix. Calls determinant to calculate the determinant. 
**              Prints the matrix and determinant.
************************************************************************/
int main()
{
    string sizeMatrixStr;
    int sizeMatrixInt,
        determVal;
    bool validNumber;

    cout << "Would you like to create a 2x2 or 3x3 matrix?" << endl;
    cout << "Type 2 for a 2x2 matrix or 3 for a 3x3 matrix: ";
    getline(cin, sizeMatrixStr);
    cout << endl;

    //Making sure that the matrix size is valid
    validNumber = isValid(sizeMatrixStr);

    //User reenters input if not valid
    while (!validNumber || (sizeMatrixStr != "2" && sizeMatrixStr != "3"))
    {
        cout << "You entered an invalid choice. " << endl;
        cout << "Please only type 2 for a 2x2 matrix or 3 for a 3x3 matrix: ";
        getline(cin, sizeMatrixStr);

        validNumber = isValid(sizeMatrixStr);
    }

    //Converting matrix size to an integer to make 2d dynamic array
    sizeMatrixInt = atoi(sizeMatrixStr.c_str());

    //2d dynamic array source: https://www.youtube.com/watch?v=gNgUMA_Ur0U
    int **matrix = new int*[sizeMatrixInt];

    for (int i = 0; i < sizeMatrixInt; i++)
    {
        matrix[i] = new int[sizeMatrixInt];
    }

    //Calling function readMatrix to input numbers into matrix
    readMatrix(matrix, sizeMatrixInt);

    //Calling function determinant to calculate the determinant
    determVal = determinant(matrix, sizeMatrixInt);

    cout << endl << "The contents of the matrix are: " << endl;
    for (int i = 0; i < sizeMatrixInt; i++)
    {
        for (int j = 0; j < sizeMatrixInt; j++)
        {
            cout << left << setw(10) << matrix[i][j] << " ";
        }

        cout << endl << endl;
    }

    cout << "The determinant for the matrix is " << determVal << endl;

    for (int i = 0; i < sizeMatrixInt; i++)
    {
        delete [] matrix[i];
    }

    delete [] matrix;

    return 0;
}