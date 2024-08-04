#include "Problem_14002.h"

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_14002::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNum = { };
    cin >> iNum;

    vector<int> vecElem;
    for (int iIdx = 0; iIdx < iNum; ++iIdx)
    {
        int iSrc = { };
        cin >> iSrc;

        vecElem.push_back(iSrc);
    }

    vector<vector<int>> vecContainer;
    for (int iRow = 0; iRow < iNum + 1; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < iNum + 1; ++iCol)
            vecSrc.push_back(0);

        vecContainer.push_back(vecSrc);
    }

    vector<vector<int>> vecMaxContainer = vecContainer;
    for (int iRow = 1; iRow < iNum + 1; ++iRow)
    {
        for (int iCol = 1; iCol < iNum + 1; ++iCol)
        {
            if (vecMaxContainer[iRow - 1][iCol - 1] < vecElem[iCol - 1])
            {
                vecContainer[iRow][iCol] = vecContainer[iRow - 1][iCol - 1] + 1;
                vecMaxContainer[iRow][iCol] = vecElem[iCol - 1];
            }
            else
            {
                vecContainer[iRow][iCol] = max(vecContainer[iRow - 1][iCol], vecContainer[iRow][iCol - 1]);
                vecMaxContainer[iRow][iCol] = max(vecMaxContainer[iRow - 1][iCol], vecMaxContainer[iRow][iCol - 1]);
            }
        }
    }

    cout << vecContainer[iNum][iNum] << '\n';

    int iRow = { iNum }, iCol = { iNum };
    vector<int> vecAnswer;
    while (true)
    {
        if (vecContainer[iRow][iCol] == max(vecContainer[iRow - 1][iCol], vecContainer[iRow][iCol - 1]))
        {
            if (vecContainer[iRow][iCol] == vecContainer[iRow - 1][iCol])
                --iRow;
            else
                --iCol;
        }
        else
        {
            vecAnswer.push_back(vecElem[iCol - 1]);
            --iRow; --iCol;
        }

        if (vecContainer[iRow][iCol] == 0)
            break;
    }

    reverse(vecAnswer.begin(), vecAnswer.end());
    for (auto iter : vecAnswer)
    {
        cout << iter << ' ';
    }

    return 0;
}
