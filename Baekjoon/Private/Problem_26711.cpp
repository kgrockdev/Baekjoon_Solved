#include "Problem_26711.h"

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_26711::Solve_Problem()
{
    string strA = { }, strB = { }, strAnswer = { };
    cin >> strA >> strB;

    int iMaxDigit = ((strA.length() > strB.length()) ? strA.length() : strB.length());

    int iUpper = { };
    for (int iDigit = 0; iDigit < iMaxDigit; ++iDigit)
    {
        if (strA.length() > 0 && strB.length() > 0)
        {
            char chA = { strA.back() }, chB = { strB.back() };
            strA.pop_back(); strB.pop_back();

            int iSrc = (chA - '0') + (chB - '0') + iUpper;

            iUpper = iSrc / 10;
            strAnswer.push_back(iSrc % 10 + '0');
        }
        else
        {
            if (strA.length() > 0)
            {
                char chA = { strA.back() };
                strA.pop_back();

                int iSrc = (chA - '0') + iUpper;

                iUpper = iSrc / 10;
                strAnswer.push_back(iSrc % 10 + '0');
            }
            else
            {
                char chB = { strB.back() };
                strB.pop_back();

                int iSrc = (chB - '0') + iUpper;

                iUpper = iSrc / 10;
                strAnswer.push_back(iSrc % 10 + '0');
            }
        }
    }

    if (iUpper != 0)
        strAnswer.push_back(iUpper + '0');

    reverse(strAnswer.begin(), strAnswer.end());

    cout << strAnswer << endl;

    return 0;
}
