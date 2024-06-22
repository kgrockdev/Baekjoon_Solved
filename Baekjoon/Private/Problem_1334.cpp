#include "Problem_1334.h"

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string BigAdd_1334(string strSrc)
{
    string strTemp = strSrc;
    int iDigit = { }, iCarry = { 1 };
    while (iCarry > 0)
    {
        if (strTemp.length() - iDigit - 1 == -1)
        {
            strTemp = '1' + strTemp;
            break;
        }

        char chSrc = strTemp[strTemp.length() - iDigit - 1];
        if (chSrc == '9')
        {
            strTemp[strTemp.length() - iDigit - 1] = '0';
            ++iCarry;
            ++iDigit;
        }
        else
        {
            strTemp[strTemp.length() - iDigit - 1] = strTemp[strTemp.length() - iDigit - 1] + 1;
            iCarry = 0;
        }
    }

    return strTemp;
}

int CProblem_1334::Solve_Problem()
{
    string strNum = { };
    cin >> strNum;

    if (strNum.length() % 2 == 0)
    {
        string strSrc = { };
        for (int iIndex = 0; iIndex < strNum.length() / 2; ++iIndex)
            strSrc.push_back(strNum[iIndex]);

        for (int iIndex = strNum.length() / 2 - 1; iIndex >= 0; --iIndex)
            strSrc.push_back(strNum[iIndex]);

        if (strSrc <= strNum)
        {
            int iNum = strSrc.length() / 2;
            if (strSrc[strNum.length() / 2] == '9')
            {
                strSrc = { };
                for (int iIndex = 0; iIndex < strNum.length() / 2; ++iIndex)
                    strSrc.push_back(strNum[iIndex]);

                strSrc = BigAdd_1334(strSrc);

                string strRev = strSrc;
                reverse(strRev.begin(), strRev.end());

                if (strSrc.length() > iNum)
                    strSrc.pop_back();

                strSrc = strSrc + strRev;
            }
            else
            {
                strSrc[strNum.length() / 2 - 1] = strSrc[strNum.length() / 2 - 1] + 1;
                strSrc[strNum.length() / 2] = strSrc[strNum.length() / 2] + 1;
            }
        }

        cout << strSrc << endl;
    }
    else
    {
        string strSrc = { };
        for (int iIndex = 0; iIndex < strNum.length() / 2; ++iIndex)
            strSrc.push_back(strNum[iIndex]);

        for (int iIndex = strNum.length() / 2; iIndex >= 0; --iIndex)
            strSrc.push_back(strNum[iIndex]);

        if (strSrc <= strNum)
        {
            int iNum = strSrc.length() / 2 + 1;
            if (strSrc[strNum.length() / 2] == '9')
            {
                strSrc = { };
                for (int iIndex = 0; iIndex < strNum.length() / 2 + 1; ++iIndex)
                    strSrc.push_back(strNum[iIndex]);

                strSrc = BigAdd_1334(strSrc);

                string strRev = strSrc;

                strSrc.pop_back();
                if (strSrc.length() + 1 > iNum)
                    strRev.pop_back();

                reverse(strRev.begin(), strRev.end());
                strSrc = strSrc + strRev;
            }
            else
            {
                strSrc[strNum.length() / 2] = strSrc[strNum.length() / 2] + 1;
            }
        }

        cout << strSrc << endl;
    }

    return 0;
}

// 9 > 11
// 191 > 202 : 2002
// 999 > 1001 : 100001