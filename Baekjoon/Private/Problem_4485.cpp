#include "Problem_4485.h"

#include <list>
#include <vector>
#include <iostream>

#define INT_MAX       2147483647

using namespace std;

typedef struct tagElement4485
{
    int iX = { };
    int iY = { };
    int iTotal = { };
} ELEM4485;

int CProblem_4485::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNum = { }, iSrc = { }, iTC = { 1 };
    while (true)
    {
        cin >> iNum;
        if (iNum == 0)
            break;

        vector<vector<int>> vecMaze;
        vector<vector<int>> vecShortMaze;
        for (int iRow = 0; iRow < iNum; ++iRow)
        {
            vector<int> vecSrc;
            vector<int> vecShortSrc;
            for (int iCol = 0; iCol < iNum; ++iCol)
            {
                cin >> iSrc;
                vecSrc.push_back(iSrc);
                vecShortSrc.push_back(INT_MAX);
            }
            vecMaze.push_back(vecSrc);
            vecShortMaze.push_back(vecShortSrc);
        }

        list<ELEM4485> lstBFS;
        lstBFS.push_back({ 0, 0, vecMaze[0][0] });

        while (lstBFS.size() > 0)
        {
            ELEM4485 tElem = lstBFS.front();
            lstBFS.pop_front();

            if (tElem.iX == iNum - 1 && tElem.iY == iNum - 1)
                continue;

            if (tElem.iX - 1 >= 0) // аб
            {
                if (vecShortMaze[tElem.iX - 1][tElem.iY] > tElem.iTotal + vecMaze[tElem.iX - 1][tElem.iY])
                {
                    lstBFS.push_back({ tElem.iX - 1, tElem.iY, tElem.iTotal + vecMaze[tElem.iX - 1][tElem.iY] });
                    vecShortMaze[tElem.iX - 1][tElem.iY] = tElem.iTotal + vecMaze[tElem.iX - 1][tElem.iY];
                }
            }
            if (tElem.iX + 1 < iNum) // ©Л
            {
                if (vecShortMaze[tElem.iX + 1][tElem.iY] > tElem.iTotal + vecMaze[tElem.iX + 1][tElem.iY])
                {
                    lstBFS.push_back({ tElem.iX + 1, tElem.iY, tElem.iTotal + vecMaze[tElem.iX + 1][tElem.iY] });
                    vecShortMaze[tElem.iX + 1][tElem.iY] = tElem.iTotal + vecMaze[tElem.iX + 1][tElem.iY];
                }
            }
            if (tElem.iY - 1 >= 0) // ╩С
            {
                if (vecShortMaze[tElem.iX][tElem.iY - 1] > tElem.iTotal + vecMaze[tElem.iX][tElem.iY - 1])
                {
                    lstBFS.push_back({ tElem.iX, tElem.iY - 1, tElem.iTotal + vecMaze[tElem.iX][tElem.iY - 1] });
                    vecShortMaze[tElem.iX][tElem.iY - 1] = tElem.iTotal + vecMaze[tElem.iX][tElem.iY - 1];
                }
            }
            if (tElem.iY + 1 < iNum) // го
            {
                if (vecShortMaze[tElem.iX][tElem.iY + 1] > tElem.iTotal + vecMaze[tElem.iX][tElem.iY + 1])
                {
                    lstBFS.push_back({ tElem.iX, tElem.iY + 1, tElem.iTotal + vecMaze[tElem.iX][tElem.iY + 1] });
                    vecShortMaze[tElem.iX][tElem.iY + 1] = tElem.iTotal + vecMaze[tElem.iX][tElem.iY + 1];
                }
            }
        }

        cout << "Problem " << iTC++ << ": " << vecShortMaze[iNum - 1][iNum - 1] << '\n';
    }

    return 0;
}
