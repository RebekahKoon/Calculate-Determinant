/************************************************************************
** Program name: lab1
** Author:       Rebekah Koon
** Date:         6/24/19
** Description:  Header file for void function readMatrix, which takes
**               a pointer to a 2D array representing a matrix and the
**               size of the matrix as parameters and prompts the user to
**               enter integers for a matrix. Calls isValid to determine
**               if input is valid. If it is valid, fills the matrix with 
**               the inputted value.
************************************************************************/

#ifndef READ_MATRIX_HPP
#define READ_MATRIX_HPP

void readMatrix(int **arr, int sizeMatrix);

#endif