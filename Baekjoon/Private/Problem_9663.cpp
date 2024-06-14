#include "Problem_9663.h"

#include <vector>
#include <iostream>

using namespace std;

int Recursive_9663(vector<int>& vecBoard, int iNumRowCol, int iRow, int iCol)
{
    if (iRow > iNumRowCol - 2)
        return 1;

    int iAnswer = { };
    for (int iNextCol = 0; iNextCol < iNumRowCol; ++iNextCol)
    {
        bool bCheck = { false };
        for (int iNavRow = 0; iNavRow < iRow + 1; ++iNavRow)
        {
            if (vecBoard[iNavRow] == iNextCol)
            {
                bCheck = true;
                break;
            }

            if (abs(vecBoard[iNavRow] - iNextCol) == (iRow + 1) - iNavRow)
            {
                bCheck = true;
                break;
            }
        }
        if (bCheck == true)
            continue;

        vecBoard[iRow + 1] = iNextCol;
        iAnswer += Recursive_9663(vecBoard, iNumRowCol, iRow + 1, iNextCol);
        vecBoard[iRow + 1] = 0;
    }

    return iAnswer;
}

int CProblem_9663::Solve_Problem()
{
    int iNumRowCol = { };
    cin >> iNumRowCol;

    vector<int> vecBoard;
    vecBoard.reserve(iNumRowCol);

    for (int iCol = 0; iCol < iNumRowCol; ++iCol)
        vecBoard.push_back(0);

    int iAnswer = { };
    for (int iCol = 0; iCol < iNumRowCol; ++iCol)
    {
        vecBoard[0] = iCol;
        iAnswer += Recursive_9663(vecBoard, iNumRowCol, 0, iCol);
        vecBoard[0] = 0;
    }

    cout << iAnswer << '\n';

    return 0;
}


/*

int Recursive_9663(vector<vector<int>>& vecBoard, int iNumRowCol, int iRow, int iCol)
{
    if (iRow > iNumRowCol - 2)
        return 1;

    vector<vector<int>> vecSrc = vecBoard;
    vecSrc[iRow][iCol] = 1;

    int iRecursive = { 0 };
    int iNavRow = { iRow };
    for (int iNavRow = iRow + 1; iNavRow < iNumRowCol; ++iNavRow)
    {
        ++iRecursive;

        // 아래 직선 검사
        vecSrc[iNavRow][iCol] = 2;

        // 왼쪽 대각선 검사
        if (iCol - iRecursive >= 0)
            vecSrc[iNavRow][iCol - iRecursive] = 2;

        // 오른쪽 대각선 검사
        if (iCol + iRecursive < iNumRowCol)
            vecSrc[iNavRow][iCol + iRecursive] = 2;
    }

    int iAnswer = { };
    for (int iNextCol = 0; iNextCol < iNumRowCol; ++iNextCol)
    {
        if (vecSrc[iRow + 1][iNextCol] != 2)
            iAnswer += Recursive_9663(vecSrc, iNumRowCol, iRow + 1, iNextCol);
    }

    return iAnswer;
}

int CProblem_9663::Solve_Problem()
{
    int iNumRowCol = { };
    cin >> iNumRowCol;

    vector<vector<int>> vecBoard;
    vecBoard.reserve(iNumRowCol);

    for (int iRow = 0; iRow < iNumRowCol; ++iRow)
    {
        vector<int> vecSrc;
        vecSrc.reserve(iNumRowCol);

        for (int iCol = 0; iCol < iNumRowCol; ++iCol)
            vecSrc.push_back(0);

        vecBoard.push_back(vecSrc);
    }

    int iAnswer = { };
    for (int iCol = 0; iCol < iNumRowCol; ++iCol)
    {
        vecBoard[0][iCol] = 1;
        iAnswer += Recursive_9663(vecBoard, iNumRowCol, 0, iCol);
    }

    cout << iAnswer << '\n';

    return 0;
}

*/