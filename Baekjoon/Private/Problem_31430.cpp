#include "Problem_31430.h"

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string Conv_31430(unsigned long long ullSrc)
{
    const char chDigits[] = "abcdefghijklmnopqrstuvwxyz";

    string strRes = { };
    while (ullSrc > 0)
    {
        strRes += chDigits[ullSrc % 26];
        ullSrc /= 26;
    }

    reverse(strRes.begin(), strRes.end());

    return strRes;
}

int CProblem_31430::Solve_Problem()
{
    int iT = { };
    cin >> iT;

    if (iT == 1)
    {
        unsigned long long ullA = { }, ullB = { };
        cin >> ullA >> ullB;

        string strSrc = Conv_31430(ullA + ullB);

        while (strSrc.size() < 13)
            strSrc = 'a' + strSrc;

        cout << strSrc << endl;
    }

    if (iT == 2)
    {
        string strSrc = { };
        cin >> strSrc;

        for (auto& iter : strSrc)
        {
            if (iter <= 'j')
                iter -= 49;
            else
                iter -= 10;
        }

        cout << stoull(strSrc, nullptr, 26) << endl;
    }

    return 0;
}
