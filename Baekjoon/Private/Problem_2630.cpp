#include "Problem_2630.h"

#include <vector>
#include <iostream>

using namespace std;

typedef struct tagElement
{
    int iX = { };
    int iY = { };

    int iLength = { };
} ELEM;

pair<int, int> CalcFunc_2630(vector<vector<int>>& vecPaper, ELEM tElem)
{
    if (tElem.iLength == 1)
    {
        if (vecPaper[tElem.iY][tElem.iX] == 0) 
            return { 1, 0 };
        else
            return { 0, 1 };
    }
    else
    {
        pair<int, int> pairLT = CalcFunc_2630(vecPaper, { tElem.iX, tElem.iY, tElem.iLength / 2 });
        pair<int, int> pairRT = CalcFunc_2630(vecPaper, { tElem.iX + tElem.iLength / 2, tElem.iY, tElem.iLength / 2 });
        pair<int, int> pairLB = CalcFunc_2630(vecPaper, { tElem.iX, tElem.iY + tElem.iLength / 2, tElem.iLength / 2 });
        pair<int, int> pairRB = CalcFunc_2630(vecPaper, { tElem.iX + tElem.iLength / 2, tElem.iY + tElem.iLength / 2, tElem.iLength / 2 });

        if (pairLT == pair<int, int>{ 1, 0 }&&
            pairRT == pair<int, int>{ 1, 0 }&&
            pairLB == pair<int, int>{ 1, 0 }&&
            pairRB == pair<int, int>{ 1, 0 })
            return { 1, 0 };
        if (pairLT == pair<int, int>{ 0, 1 }&&
            pairRT == pair<int, int>{ 0, 1 }&&
            pairLB == pair<int, int>{ 0, 1 }&&
            pairRB == pair<int, int>{ 0, 1 })
            return { 0, 1 };

        pair<int, int> pairRes = { };
        pairRes.first = pairLT.first + pairRT.first + pairLB.first + pairRB.first;
        pairRes.second = pairLT.second + pairRT.second + pairLB.second + pairRB.second;

        return pairRes;
    }
}

int CProblem_2630::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumLength = { }, iSrc = { };
    cin >> iNumLength;

    vector<vector<int>> vecPaper;
    vecPaper.reserve(iNumLength);

    for (int iRow = 0; iRow < iNumLength; ++iRow)
    {
        vector<int> vecSrc;
        vecSrc.reserve(iNumLength);
        for (int iCol = 0; iCol < iNumLength; ++iCol)
        {
            cin >> iSrc;
            vecSrc.push_back(iSrc);
        }

        vecPaper.push_back(vecSrc);
    }

    pair<int, int> pairRes = CalcFunc_2630(vecPaper, { 0, 0, iNumLength });
    cout << pairRes.first << endl;
    cout << pairRes.second << endl;

    return 0;
}
