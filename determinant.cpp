/************************************************************************
** Program name: lab1
** Author:       Rebekah Koon
** Date:         6/24/19
** Description:  Source file for function determinant, which is used to
**               calculate the determinant of a 2x2 or 3x3 matrix.
************************************************************************/

#include "determinant.hpp"


/************************************************************************
** Description: Function determinant takes a 2D array representing a
**              matrix and the size of the array as parameters.
**              Determines whether the matrix is 2x2 or 3x3 and then
**              calculates its determinant. Returns the determinant.
************************************************************************/
int determinant(int **arr, int sizeMatrix)
{
    int determ;

    //Determinant if matrix is 2x2
    if (sizeMatrix == 2)
    {
        determ = (arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]);
    }

    //Determinant if matrix is 3x3
    else
    {
        int columnA,
            columnB,
            columnC;

        //Calculating the determinant of each submatrix within the 3x3 matrix
        columnA = arr[0][0] * (arr[1][1] * arr[2][2] - arr[1][2] * arr[2][1]);
        columnB = arr[0][1] * (arr[1][0] * arr[2][2] - arr[1][2] * arr[2][0]);
        columnC = arr[0][2] * (arr[1][0] * arr[2][1] - arr[1][1] * arr[2][0]);

        determ = columnA - columnB + columnC;
    }

    return determ;
}