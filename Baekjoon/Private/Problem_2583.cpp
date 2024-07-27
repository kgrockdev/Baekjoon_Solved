#include "Problem_2583.h"

#include <list>
#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF 100000000

int CProblem_2583::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int iNumRow = { }, iNumCol = { }, iNumRect = { };
    cin >> iNumRow >> iNumCol >> iNumRect;

    vector<vector<int>> vecContainer;

    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < iNumCol; ++iCol)
            vecSrc.push_back(0);

        vecContainer.push_back(vecSrc);
    }

    list<pair<int, int>> lstSearch;
    for (int iRect = 0; iRect < iNumRect; ++iRect)
    {
        int iPointAX = { }, iPointAY = { };
        int iPointBX = { }, iPointBY = { };
        cin >> iPointAX >> iPointAY >> iPointBX >> iPointBY;

        iPointAY = abs(iPointAY - iNumRow);
        iPointBY = abs(iPointBY - iNumRow);

        for (int iRow = iPointBY; iRow < iPointAY; ++iRow)
        {
            for (int iCol = iPointAX; iCol < iPointBX; ++iCol)
            {
                vecContainer[iRow][iCol] += 1;
            }
        }
    }

    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        for (int iCol = 0; iCol < iNumCol; ++iCol)
        {
            if (vecContainer[iRow][iCol] == 0)
                lstSearch.push_back({ iRow, iCol });
        }
    }

    priority_queue<int, vector<int>, greater<int>> pqContainer;
    while (lstSearch.size() > 0)
    {
        pair<int, int> pairSrc = lstSearch.front();
        lstSearch.pop_front();

        if (vecContainer[pairSrc.first][pairSrc.second] != 0)
            continue;

        vecContainer[pairSrc.first][pairSrc.second] = INF;

        list<pair<int, int>> lstBFS;
        lstBFS.push_back(pairSrc);

        int iSize = { 0 };
        while (lstBFS.size() > 0)
        {
            pair<int, int> pairSearch = lstBFS.front();
            lstBFS.pop_front();
            ++iSize;

            // T
            if (pairSearch.first > 0 &&
                vecContainer[pairSearch.first - 1][pairSearch.second] == 0)
            {
                lstBFS.push_back({ pairSearch.first - 1, pairSearch.second });
                vecContainer[pairSearch.first - 1][pairSearch.second] = INF;
            }

            // B
            if (pairSearch.first < iNumRow - 1 &&
                vecContainer[pairSearch.first + 1][pairSearch.second] == 0)
            {
                lstBFS.push_back({ pairSearch.first + 1, pairSearch.second });
                vecContainer[pairSearch.first + 1][pairSearch.second] = INF;
            }

            // L
            if (pairSearch.second > 0 &&
                vecContainer[pairSearch.first][pairSearch.second - 1] == 0)
            {
                lstBFS.push_back({ pairSearch.first, pairSearch.second - 1 });
                vecContainer[pairSearch.first][pairSearch.second - 1] = INF;
            }

            // R
            if (pairSearch.second < iNumCol - 1 &&
                vecContainer[pairSearch.first][pairSearch.second + 1] == 0)
            {
                lstBFS.push_back({ pairSearch.first, pairSearch.second + 1 });
                vecContainer[pairSearch.first][pairSearch.second + 1] = INF;
            }
        }
        
        pqContainer.emplace(iSize);
    }

    cout << pqContainer.size() << '\n';
    while (pqContainer.size() > 0)
    {
        cout << pqContainer.top() << " ";
        pqContainer.pop();
    }
    
    return 0;
}
