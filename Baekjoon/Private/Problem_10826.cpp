#include "Problem_10826.h"

using namespace std;

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

unordered_map<int, string> mapMemo;

string Calc_StringAppend(string strA, string strB)
{
    int iLength = max(strA.size(), strB.size());

    if (strA.size() < iLength)
    {
        string strZero = { };

        for (int iIndex = 0; iIndex < iLength - strA.size(); ++iIndex)
            strZero += "0";

        strA = strZero + strA;
    }
    if (strB.size() < iLength)
    {
        string strZero = { };

        for (int iIndex = 0; iIndex < iLength - strB.size(); ++iIndex)
            strZero += "0";

        strB = strZero + strB;
    }

    reverse(strA.begin(), strA.end());
    reverse(strB.begin(), strB.end());

    int iCarry = { };
    string strRes = { };
    for (int iIndex = 0; iIndex < iLength; ++iIndex)
    {
        int iTemp = int(strA[iIndex] - '0') + int(strB[iIndex] - '0') + iCarry;

        iCarry = iTemp / 10;
        strRes += to_string(iTemp % 10);
    }

    if (iCarry != 0)
        strRes += to_string(iCarry);

    reverse(strRes.begin(), strRes.end());

    return strRes;
}

string Calc_Fibb(int iSrc)
{
    auto iter = mapMemo.find(iSrc);
    if (iter != mapMemo.end())
        return iter->second;
    else
    {
        if (iSrc > 1)
        {
            string strTemp = Calc_StringAppend(Calc_Fibb(iSrc - 1), Calc_Fibb(iSrc - 2));
            mapMemo.emplace(iSrc, strTemp);

            return strTemp;
        }
        else
            return to_string(iSrc);
    }
}

int CProblem_10826::Solve_Problem()
{
    int iQuery = { };
    cin >> iQuery;

    cout << Calc_Fibb(iQuery) << '\n';

    return 0;
}
