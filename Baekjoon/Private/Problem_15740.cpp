#include "Problem_15740.h"

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string Calc_15740(string strA, string strB)
{
    string strSrc = { };
    int iDigit = { }, iRound = { };

    if (strA.length() < strB.length())
        swap(strA, strB);

    if ((strA.front() == '-' && strB.front() != '-') ||
        (strA.front() != '-' && strB.front() == '-'))
    {
        if (strA.front() == '-')
            strA.erase(0, 1);
        else
            strB.erase(0, 1);

        while (strB.length() > 0)
        {
            char chSrcA = strA.back();
            char chSrcB = strB.back();
            strA.pop_back();
            strB.pop_back();

            int iSrc = (chSrcA - '0') - (chSrcB - '0') - iRound;
            if (iSrc < 0)
            {
                iSrc += 10;
                iRound = 1;
            }
            else
                iRound = 0;

            strSrc.push_back((iSrc % 10) + '0');
        }

        reverse(strSrc.begin(), strSrc.end());
    }
    else
    {
        int iCheckDigit = 0;
        if (strA.front() == '-' && strB.front() == '-')
            iCheckDigit = 1;

        while (strB.length() > iCheckDigit)
        {
            char chSrcA = strA.back();
            char chSrcB = strB.back();
            strA.pop_back();
            strB.pop_back();

            int iSrc = (chSrcA - '0') + (chSrcB - '0') + iRound;
            strSrc.push_back((iSrc % 10) + '0');
            iRound = iSrc / 10;
        }

        while (strA.length() > iCheckDigit)
        {
            char chSrcA = strA.back();
            strA.pop_back();

            int iSrc = (chSrcA - '0') + iRound;
            strSrc.push_back((iSrc % 10) + '0');
            iRound = iSrc / 10;
        }

        if (iCheckDigit == 1)
            strSrc.push_back('-');

        reverse(strSrc.begin(), strSrc.end());
    }

    return strSrc;
}

int CProblem_15740::Solve_Problem()
{
    string strA = { }, strB = { };
    cin >> strA >> strB;

    cout << Calc_15740(strA, strB) << endl;

    return 0;
}
