/************************************************************************
** Program name: lab1
** Author:       Rebekah Koon
** Date:         6/24/19
** Description:  Source file for function isValid, which checks to see if
**               a string is a valid integer.
************************************************************************/

#include "isValid.hpp"
#include <string>

using std::string;

/************************************************************************
** Description: Function isValid takes a string as a parameter and checks
**              to see if the string is an integer. If the string is an
**              integer, returns true. If not, returns false.
**              Source used for input validation: 
**              http://www.cplusplus.com/forum/beginner/168067/
************************************************************************/
bool isValid(string sizeAsStr)
{
    bool valid = true;

    //Checking to see if the string is a single digit
    if ((sizeAsStr.length() == 1) && (!isdigit(sizeAsStr[0])))
    {
        valid = false;
    }

    else
    {
        //Checking to see if the input is a negative integer
        if ((!isdigit(sizeAsStr[0])) && (sizeAsStr[0] != '-'))
        {
            valid = false;
        }

        //Making sure other characters in the string are digits
        for (int i = 1; i < sizeAsStr.length(); i++)
        {
            if (!isdigit(sizeAsStr[i]))
            {
                valid = false;
            }
        }
    }

    return valid;
}