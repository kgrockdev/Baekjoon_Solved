#include "Problem_7576.h"

#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct tagElement7576
{
    int iRow = { };
    int iCol = { };
    int iDay = { };
} ELEM7576;

int CProblem_7576::Solve_Problem()
{
    int iNumRow = { }, iNumCol = { }, iSrc = { };
    cin >> iNumCol >> iNumRow;

    list<ELEM7576> lstBFS;
    vector<vector<int>> vecMaze;
    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < iNumCol; ++iCol)
        {
            cin >> iSrc;
            vecSrc.push_back(iSrc);

            if (iSrc == 1)
                lstBFS.push_back({ iRow, iCol, 0 });
        }
        vecMaze.push_back(vecSrc);
    }

    int iMaxDay = { 0 };
    while (lstBFS.size() > 0)
    {
        ELEM7576 tElemPos = lstBFS.front();
        lstBFS.pop_front();

        iMaxDay = max(iMaxDay, tElemPos.iDay);

        // ╩С
        if (tElemPos.iRow > 0 && vecMaze[tElemPos.iRow - 1][tElemPos.iCol] == 0)
        {
            lstBFS.push_back({ tElemPos.iRow - 1, tElemPos.iCol, tElemPos.iDay + 1 });
            vecMaze[tElemPos.iRow - 1][tElemPos.iCol] = 1;
        }

        // го
        if (tElemPos.iRow < iNumRow - 1 && vecMaze[tElemPos.iRow + 1][tElemPos.iCol] == 0)
        {
            lstBFS.push_back({ tElemPos.iRow + 1, tElemPos.iCol, tElemPos.iDay + 1 });
            vecMaze[tElemPos.iRow + 1][tElemPos.iCol] = 1;
        }
        
        // аб
        if (tElemPos.iCol > 0 && vecMaze[tElemPos.iRow][tElemPos.iCol - 1] == 0)
        {
            lstBFS.push_back({ tElemPos.iRow, tElemPos.iCol - 1, tElemPos.iDay + 1 });
            vecMaze[tElemPos.iRow][tElemPos.iCol - 1] = 1;
        }
        
        // ©Л
        if (tElemPos.iCol < iNumCol - 1 && vecMaze[tElemPos.iRow][tElemPos.iCol + 1] == 0)
        {
            lstBFS.push_back({ tElemPos.iRow, tElemPos.iCol + 1, tElemPos.iDay + 1 });
            vecMaze[tElemPos.iRow][tElemPos.iCol + 1] = 1;
        }
    }

    for (auto row : vecMaze)
    {
        for (auto col : row)
        {
            if (col == 0)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << iMaxDay << endl;

    return 0;
}
