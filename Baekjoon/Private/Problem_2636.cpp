#include "Problem_2636.h"

#include <list>
#include <vector>
#include <iostream>

#define VISITED 2

using namespace std;

int CProblem_2636::Solve_Problem()
{
    int iNumRow = { }, iNumCol = { };
    cin >> iNumRow >> iNumCol;

    vector<vector<int>> vecContainer;

    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < iNumCol; ++iCol)
        {
            int iSrc = { };
            cin >> iSrc;

            vecSrc.push_back(iSrc);
        }

        vecContainer.push_back(vecSrc);
    }

    int iAnsTime = { }, iAnsCount = { };
    while (true)
    {
        list<pair<int, int>> lstBFS;
        lstBFS.push_back({ 0, 0 });

        list<pair<int, int>> lstVisitedNode;
        vector<vector<int>> vecVisted = vecContainer;
        while (lstBFS.size() > 0)
        {
            pair<int, int> pairSrc = lstBFS.front();
            lstBFS.pop_front();

            // T
            if (pairSrc.first > 0 &&
                vecVisted[pairSrc.first - 1][pairSrc.second] != 2)
            {
                if (vecVisted[pairSrc.first - 1][pairSrc.second] == 0)
                {
                    vecVisted[pairSrc.first - 1][pairSrc.second] = VISITED;
                    lstBFS.push_back({ pairSrc.first - 1, pairSrc.second });
                }
                else if (vecVisted[pairSrc.first - 1][pairSrc.second] == 1)
                {
                    vecVisted[pairSrc.first - 1][pairSrc.second] = VISITED;
                    lstVisitedNode.push_back({ pairSrc.first - 1, pairSrc.second });
                }
            }

            // B
            if (pairSrc.first < iNumRow - 1 &&
                vecVisted[pairSrc.first + 1][pairSrc.second] != 2)
            {
                if (vecVisted[pairSrc.first + 1][pairSrc.second] == 0)
                {
                    vecVisted[pairSrc.first + 1][pairSrc.second] = VISITED;
                    lstBFS.push_back({ pairSrc.first + 1, pairSrc.second });
                }
                else if (vecVisted[pairSrc.first + 1][pairSrc.second] == 1)
                {
                    vecVisted[pairSrc.first + 1][pairSrc.second] = VISITED;
                    lstVisitedNode.push_back({ pairSrc.first + 1, pairSrc.second });
                }
            }

            // L
            if (pairSrc.second > 0 &&
                vecVisted[pairSrc.first][pairSrc.second - 1] != 2)
            {
                if (vecVisted[pairSrc.first][pairSrc.second - 1] == 0)
                {
                    vecVisted[pairSrc.first][pairSrc.second - 1] = VISITED;
                    lstBFS.push_back({ pairSrc.first, pairSrc.second - 1 });
                }
                else if (vecVisted[pairSrc.first][pairSrc.second - 1] == 1)
                {
                    vecVisted[pairSrc.first][pairSrc.second - 1] = VISITED;
                    lstVisitedNode.push_back({ pairSrc.first, pairSrc.second - 1 });
                }
            }

            // R
            if (pairSrc.second < iNumCol - 1 &&
                vecVisted[pairSrc.first][pairSrc.second + 1] != 2)
            {
                if (vecVisted[pairSrc.first][pairSrc.second + 1] == 0)
                {
                    vecVisted[pairSrc.first][pairSrc.second + 1] = VISITED;
                    lstBFS.push_back({ pairSrc.first, pairSrc.second + 1 });
                }
                else if (vecVisted[pairSrc.first][pairSrc.second + 1] == 1)
                {
                    vecVisted[pairSrc.first][pairSrc.second + 1] = VISITED;
                    lstVisitedNode.push_back({ pairSrc.first, pairSrc.second + 1 });
                }
            }
        }

        if (lstVisitedNode.size() == 0)
            break;

        for (auto& iter : lstVisitedNode)
        {
            vecContainer[iter.first][iter.second] = 0;
        }
        
        ++iAnsTime;
        iAnsCount = lstVisitedNode.size();
    }

    cout << iAnsTime << '\n' << iAnsCount;

    return 0;
}
