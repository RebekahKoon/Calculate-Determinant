## Program name: lab1
## Author:       Rebekah Koon
## Date:         6/24/19
## Description:  Makefile that compiles a program which asks the user
##               to make either a 2x2 or 3x3 matrix, asks for user
##               input on the values within the matrix, and then
##               prints the matrix and its determinant.

lab1: main.o readMatrix.o determinant.o isValid.o
	g++ -g main.o readMatrix.o determinant.o isValid.o -o lab1

main.o: main.cpp
	g++ -c main.cpp

readMatrix.o: readMatrix.cpp readMatrix.hpp
	g++ -c readMatrix.cpp

determinant.o: determinant.cpp determinant.hpp
	g++ -c determinant.cpp

isValid.o: isValid.cpp isValid.hpp
	g++ -c isValid.cpp

clean:
	rm *.o lab1