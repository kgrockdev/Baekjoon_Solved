#include "Problem_17070.h"

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

enum DIRECTION
{
    DIR_NONE = 0,
    DIR_BB = 1,
    DIR_RR = 2,
    DIR_RB = 3, 
};

typedef struct tagPipe
{
    int iRow = { };
    int iCol = { };

    DIRECTION eDir = { };

    bool operator()(tagPipe tPipeA, tagPipe tPipeB)
    {
        if (tPipeA.iCol == tPipeB.iCol)
            return tPipeA.iRow > tPipeB.iRow;
        else
            return tPipeA.iCol > tPipeB.iCol;
    }
} PIPE;

int CProblem_17070::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumRowCol = { };
    cin >> iNumRowCol;

    vector<vector<int>> vecMaze;

    for (int iRow = 0; iRow < iNumRowCol; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < iNumRowCol; ++iCol)
        {
            int iSrc = { };
            cin >> iSrc;
            
            vecSrc.push_back((iSrc == 1) ? -1 : iSrc);
        }

        vecMaze.push_back(vecSrc);
    }

    if (vecMaze[iNumRowCol - 1][iNumRowCol - 1] == -1)
    {
        cout << 0 << '\n';
        return 0;
    }

    vecMaze[0][0] = 1;
    vecMaze[0][1] = 1;

    priority_queue<PIPE, vector<PIPE>, PIPE> pqBFS;
    pqBFS.emplace(PIPE{ 0, 1, DIR_RR });

    while (pqBFS.size() > 0)
    {
        PIPE ePipe = pqBFS.top();
        pqBFS.pop();

        switch (ePipe.eDir)
        {
        case DIR_RR:
            if (ePipe.iCol + 1 < iNumRowCol &&
                vecMaze[ePipe.iRow][ePipe.iCol + 1] != -1)
            {
                vecMaze[ePipe.iRow][ePipe.iCol + 1] += 1;
                pqBFS.emplace(PIPE{ ePipe.iRow, ePipe.iCol + 1, DIR_RR });
            }
            if (ePipe.iRow + 1 < iNumRowCol &&
                ePipe.iCol + 1 < iNumRowCol &&
                vecMaze[ePipe.iRow][ePipe.iCol + 1] != -1 &&
                vecMaze[ePipe.iRow + 1][ePipe.iCol] != -1 &&
                vecMaze[ePipe.iRow + 1][ePipe.iCol + 1] != -1)
            {
                vecMaze[ePipe.iRow + 1][ePipe.iCol + 1] += 1;
                pqBFS.emplace(PIPE{ ePipe.iRow + 1, ePipe.iCol + 1, DIR_RB });
            }
            break;
        case DIR_RB:
            if (ePipe.iCol + 1 < iNumRowCol &&
                vecMaze[ePipe.iRow][ePipe.iCol + 1] != -1)
            {
                vecMaze[ePipe.iRow][ePipe.iCol + 1] += 1;
                pqBFS.emplace(PIPE{ ePipe.iRow, ePipe.iCol + 1, DIR_RR });
            }
            if (ePipe.iRow + 1 < iNumRowCol &&
                ePipe.iCol + 1 < iNumRowCol &&
                vecMaze[ePipe.iRow][ePipe.iCol + 1] != -1 &&
                vecMaze[ePipe.iRow + 1][ePipe.iCol] != -1 &&
                vecMaze[ePipe.iRow + 1][ePipe.iCol + 1] != -1)
            {
                vecMaze[ePipe.iRow + 1][ePipe.iCol + 1] += 1;
                pqBFS.emplace(PIPE{ ePipe.iRow + 1, ePipe.iCol + 1, DIR_RB });
            }
            if (ePipe.iRow + 1 < iNumRowCol &&
                vecMaze[ePipe.iRow + 1][ePipe.iCol] != -1)
            {
                vecMaze[ePipe.iRow + 1][ePipe.iCol] += 1;
                pqBFS.emplace(PIPE{ ePipe.iRow + 1, ePipe.iCol, DIR_BB });
            }
            break;
        case DIR_BB:
            if (ePipe.iRow + 1 < iNumRowCol &&
                ePipe.iCol + 1 < iNumRowCol &&
                vecMaze[ePipe.iRow][ePipe.iCol + 1] != -1 &&
                vecMaze[ePipe.iRow + 1][ePipe.iCol] != -1 &&
                vecMaze[ePipe.iRow + 1][ePipe.iCol + 1] != -1)
            {
                vecMaze[ePipe.iRow + 1][ePipe.iCol + 1] += 1;
                pqBFS.emplace(PIPE{ ePipe.iRow + 1, ePipe.iCol + 1, DIR_RB });
            }
            if (ePipe.iRow + 1 < iNumRowCol &&
                vecMaze[ePipe.iRow + 1][ePipe.iCol] != -1)
            {
                vecMaze[ePipe.iRow + 1][ePipe.iCol] += 1;
                pqBFS.emplace(PIPE{ ePipe.iRow + 1, ePipe.iCol, DIR_BB });
            }
            break;
        }
    }

    cout << vecMaze[iNumRowCol - 1][iNumRowCol - 1] << '\n';

    return 0;
}
