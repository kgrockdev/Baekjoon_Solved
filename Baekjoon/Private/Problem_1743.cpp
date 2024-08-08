#include "Problem_1743.h"

#include <list>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int Search_1743(int iNumRow, int iNumCol, pair<int, int>& pairPos, vector<vector<int>>& vecContainer)
{
    list<pair<int, int>> lstBFS;
    lstBFS.push_back(pairPos);

    int iReturn = { 1 };
    while (lstBFS.size() > 0)
    {
        pair<int, int> pairSrc = lstBFS.front();
        lstBFS.pop_front();

        if (pairSrc.first > 0 &&
            vecContainer[pairSrc.first - 1][pairSrc.second] == 1)
        {
            ++iReturn;
            lstBFS.push_back(pair<int, int> { pairSrc.first - 1, pairSrc.second });
            vecContainer[pairSrc.first - 1][pairSrc.second] = 2;
        }

        if (pairSrc.second > 0 &&
            vecContainer[pairSrc.first][pairSrc.second - 1] == 1)
        {
            ++iReturn;
            lstBFS.push_back(pair<int, int> { pairSrc.first, pairSrc.second - 1 });
            vecContainer[pairSrc.first][pairSrc.second - 1] = 2;
        }

        if (pairSrc.first < iNumRow - 1 &&
            vecContainer[pairSrc.first + 1][pairSrc.second] == 1)
        {
            ++iReturn;
            lstBFS.push_back(pair<int, int> { pairSrc.first + 1, pairSrc.second });
            vecContainer[pairSrc.first + 1][pairSrc.second] = 2;
        }

        if (pairSrc.second < iNumCol - 1 &&
            vecContainer[pairSrc.first][pairSrc.second + 1] == 1)
        {
            ++iReturn;
            lstBFS.push_back(pair<int, int> { pairSrc.first, pairSrc.second + 1 });
            vecContainer[pairSrc.first][pairSrc.second + 1] = 2;
        }
    }

    return iReturn;
}

int CProblem_1743::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumRow = { }, iNumCol = { }, iNumTrash = { };
    cin >> iNumRow >> iNumCol >> iNumTrash;

    vector<vector<int>> vecContainer;
    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < iNumCol; ++iCol)
            vecSrc.push_back(0);

        vecContainer.push_back(vecSrc);
    }

    for (int iTrash = 0; iTrash < iNumTrash; ++iTrash)
    {
        int iRow = { }, iCol = { };
        cin >> iRow >> iCol;

        vecContainer[iRow - 1][iCol - 1] = 1;
    }

    int iMaxAnswer = { 0 };
    while (true)
    {
        bool bFind = { false };
        pair<int, int> pairPos = { };
        for (int iRow = 0; iRow < iNumRow; ++iRow)
        {
            for (int iCol = 0; iCol < iNumCol; ++iCol)
            {
                if (vecContainer[iRow][iCol] == 1)
                {
                    bFind = true;
                    pairPos.first = iRow;
                    pairPos.second = iCol;
                    vecContainer[iRow][iCol] = 2;

                    break;
                }
            }

            if (bFind == true)
                break;
        }

        if (bFind == false)
            break;

        int iSrc = Search_1743(iNumRow, iNumCol, pairPos, vecContainer);
        iMaxAnswer = max(iSrc, iMaxAnswer);
    }

    cout << iMaxAnswer;

    return 0;
}

