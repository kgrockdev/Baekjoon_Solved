#include "Problem_1926.h"

#include <list>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int Search_1926(vector<vector<int>>& vecContainer, pair<int, int> pairPos, int iNumRow, int iNumCol)
{
    int iReturn = { 1 };

    list<pair<int, int>> lstBFS;
    lstBFS.push_back(pairPos);

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

int CProblem_1926::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumRow = { }, iNumCol = { };
    cin >> iNumRow >> iNumCol;

    list<pair<int, int>> lstSearch;
    vector<vector<int>> vecContainer;
    vecContainer.reserve(iNumRow + 1);

    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        vector<int> vecSrc;
        vecSrc.reserve(iNumCol + 1);

        for (int iCol = 0; iCol < iNumCol; ++iCol)
        {
            int iSrc = { };
            cin >> iSrc;

            vecSrc.push_back(iSrc);

            if (iSrc == 1)
                lstSearch.push_back({ iRow, iCol });
        }

        vecContainer.push_back(vecSrc);
    }

    int iNumPic = { }, iNumSize = { 0 };
    while (true)
    {
        bool bFind = { false };
        pair<int, int> pairPos = { };

        while (lstSearch.size() > 0)
        {
            pair<int, int> pairSrc = lstSearch.front();
            lstSearch.pop_front();

            if (vecContainer[pairSrc.first][pairSrc.second] == 2)
                continue;

            vecContainer[pairSrc.first][pairSrc.second] = 2;
            pairPos = pairSrc;
            ++iNumPic;

            bFind = true;
            break;
        }

        if (bFind == false)
            break;

        int iSrc = Search_1926(vecContainer, pairPos, iNumRow, iNumCol);
        iNumSize = max(iNumSize, iSrc);
    }

    cout << iNumPic << '\n' << iNumSize;

    return 0;
}
