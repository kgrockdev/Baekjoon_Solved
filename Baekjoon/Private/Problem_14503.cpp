#include "Problem_14503.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_14503::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumRow = { }, iNumCol = { };
    cin >> iNumRow >> iNumCol;

    int iCurrRow = { }, iCurrCol = { }, iCurrRot = { };
    cin >> iCurrRow >> iCurrCol >> iCurrRot;

    vector<vector<int>> vecMaze;
    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < iNumCol; ++iCol)
        {
            int iSrc = { };
            cin >> iSrc;

            vecSrc.push_back(iSrc);
        }
        vecMaze.push_back(vecSrc);
    }

    int iClean = { };
    while (true)
    {
        static bool bBreak = { false };

        if (vecMaze[iCurrRow][iCurrCol] == 0)
        {
            ++iClean;
            vecMaze[iCurrRow][iCurrCol] = 2;
        }

        if ((iCurrRow > 0 && vecMaze[iCurrRow - 1][iCurrCol] != 0) &&
            (iCurrRow < iNumRow - 1 && vecMaze[iCurrRow + 1][iCurrCol] != 0) &&
            (iCurrCol > 0 && vecMaze[iCurrRow][iCurrCol - 1] != 0) &&
            (iCurrCol < iNumCol - 1 && vecMaze[iCurrRow][iCurrCol + 1] != 0))
        {
            switch (iCurrRot)
            {
            case 0: // ºÏ
                if (iCurrRow < iNumRow - 1 && vecMaze[iCurrRow + 1][iCurrCol] != 1)
                    ++iCurrRow;
                else
                    bBreak = true;
                break;
            case 1: // µ¿
                if (iCurrCol > 0 && vecMaze[iCurrRow][iCurrCol - 1] != 1)
                    --iCurrCol;
                else
                    bBreak = true;
                break;
            case 2: // ³²
                if (iCurrRow > 0 && vecMaze[iCurrRow - 1][iCurrCol] != 1)
                    --iCurrRow;
                else
                    bBreak = true;
                break;
            case 3: // ¼­
                if (iCurrCol < iNumCol - 1 && vecMaze[iCurrRow][iCurrCol + 1] != 1)
                    ++iCurrCol;
                else
                    bBreak = true;
                break;
            }
        }
        else
        {
            iCurrRot = iCurrRot - 1;
            if (iCurrRot == -1) iCurrRot = 3;

            switch (iCurrRot)
            {
            case 0: // ºÏ
                if (iCurrRow > 0 && vecMaze[iCurrRow - 1][iCurrCol] == 0)
                    --iCurrRow;
                break;
            case 1: // µ¿
                if (iCurrCol < iNumCol - 1 && vecMaze[iCurrRow][iCurrCol + 1] == 0)
                    ++iCurrCol;
                break;
            case 2: // ³²
                if (iCurrRow < iNumRow - 1 && vecMaze[iCurrRow + 1][iCurrCol] == 0)
                    ++iCurrRow;
                break;
            case 3: // ¼­
                if (iCurrCol > 0 && vecMaze[iCurrRow][iCurrCol - 1] == 0)
                    --iCurrCol;
                break;
            }
        }

        if (bBreak == true)
            break;
    }

    cout << iClean << '\n';

    return 0;
}
