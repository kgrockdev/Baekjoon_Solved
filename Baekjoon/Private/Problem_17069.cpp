#include "Problem_17069.h"

#include <vector>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;
#define WALL 18000000000000000000
#define NSEARCH 17000000000000000000

vector<vector<ULL>> vecMaze;

int CProblem_17069::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumRowCol = { };
    cin >> iNumRowCol;

    for (int iRow = 0; iRow < iNumRowCol; ++iRow)
    {
        vector<ULL> vecMazeSrc;
        for (int iCol = 0; iCol < iNumRowCol; ++iCol)
        {
            int iSrc = { };
            cin >> iSrc;

            vecMazeSrc.push_back((iSrc == 1) ? WALL : 0);
        }

        vecMaze.push_back(vecMazeSrc);
    }

    vecMaze[0][0] = 0;
    vecMaze[0][1] = 1;

    for (int iRow = 0; iRow < iNumRowCol; ++iRow)
    {
        for (int iCol = 0; iCol < iNumRowCol; ++iCol)
        {
            if (iRow == 0 && iCol == 0)
                continue;
            if (iRow == 0 && iCol == 1)
                continue;
            if (vecMaze[iRow][iCol] == WALL)
                continue;

            if (iCol > 0 &&
                vecMaze[iRow][iCol - 1] != 0 &&
                vecMaze[iRow][iCol - 1] != WALL)
                vecMaze[iRow][iCol] += vecMaze[iRow][iCol - 1];

            if (iRow > 0 &&
                iCol > 0 &&
                vecMaze[iRow - 1][iCol - 1] != 0 &&
                vecMaze[iRow - 1][iCol - 1] != WALL)
                vecMaze[iRow][iCol] += vecMaze[iRow - 1][iCol - 1];

        }
    }

    for (int iRow = 0; iRow < iNumRowCol; ++iRow)
    {
        for (int iCol = 0; iCol < iNumRowCol; ++iCol)
        {
            if (vecMaze[iRow][iCol] == WALL ||
                vecMaze[iRow][iCol] == NSEARCH)
                cout << "-\t" << " ";
            else
                cout << vecMaze[iRow][iCol] << "\t";
        }
        cout << '\n';
    }

    return 0;
}


/*

typedef unsigned long long ULL;
#define WALL 18000000000000000000
#define NSEARCH 17000000000000000000

vector<vector<ULL>> vecMaze;
vector<vector<int>> vecSearch;

enum DIRECTION
{
    DIR_TT = 0b0001,
    DIR_TL = 0b0010,
    DIR_LL = 0b0100,
    DIR_NONE = 0b0000,
};

ULL Calc_17069(int iRow, int iCol, DIRECTION eDir)
{
    if (vecMaze[iRow][iCol] != NSEARCH)
    {
        if (vecSearch[iRow][iCol] & eDir)
            return vecMaze[iRow][iCol];
        else
            return 0;
    }

    ULL ullSrc = { };

    // Next TT
    if (iRow > 0 &&
        eDir != DIR_LL &&
        vecMaze[iRow - 1][iCol] != WALL)
    {
        ULL ullDst = Calc_17069(iRow - 1, iCol, DIR_TT);
        if (ullDst != 0)
        {
            vecSearch[iRow][iCol] |= DIR_TL;
            vecSearch[iRow][iCol] |= DIR_TT;
        }

        ullSrc += ullDst;
    }

    // Next TL
    if (iRow > 0 &&
        iCol > 0 &&
        vecMaze[iRow - 1][iCol] != WALL &&
        vecMaze[iRow][iCol - 1] != WALL &&
        vecMaze[iRow - 1][iCol - 1] != WALL)
    {
        ULL ullDst = Calc_17069(iRow - 1, iCol - 1, DIR_TL);
        if (ullDst != 0)
        {
            vecSearch[iRow][iCol] |= DIR_TT;
            vecSearch[iRow][iCol] |= DIR_TL;
            vecSearch[iRow][iCol] |= DIR_LL;
        }

        ullSrc += ullDst;
    }

    // Next LL
    if (iCol > 0 &&
        eDir != DIR_TT &&
        vecMaze[iRow][iCol - 1] != WALL)
    {
        ULL ullDst = Calc_17069(iRow, iCol - 1, DIR_LL);
        if (ullDst != 0)
        {
            vecSearch[iRow][iCol] |= DIR_TL;
            vecSearch[iRow][iCol] |= DIR_LL;
        }

        ullSrc += ullDst;
    }

    vecMaze[iRow][iCol] = ullSrc;

    return ullSrc;
}

int CProblem_17069::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumRowCol = { };
    cin >> iNumRowCol;

    for (int iRow = 0; iRow < iNumRowCol; ++iRow)
    {
        vector<ULL> vecMazeSrc;
        vector<int> vecSearchSrc;
        for (int iCol = 0; iCol < iNumRowCol; ++iCol)
        {
            int iSrc = { };
            cin >> iSrc;

            vecMazeSrc.push_back((iSrc == 1) ? WALL : NSEARCH);
            vecSearchSrc.push_back(DIR_NONE);
        }

        vecMaze.push_back(vecMazeSrc);
        vecSearch.push_back(vecSearchSrc);
    }

    vecMaze[0][0] = WALL;
    vecMaze[0][1] = 1;

    vecSearch[0][0] = DIR_NONE;
    vecSearch[0][1] = DIR_LL | DIR_TL;

    ULL ullAnswer = { };

    ullAnswer += Calc_17069(iNumRowCol - 2, iNumRowCol - 1, DIR_TT);
    ullAnswer += Calc_17069(iNumRowCol - 2, iNumRowCol - 2, DIR_TL);
    ullAnswer += Calc_17069(iNumRowCol - 1, iNumRowCol - 2, DIR_LL);

    cout << ullAnswer << '\n';

    for (int iRow = 0; iRow < iNumRowCol; ++iRow)
    {
        for (int iCol = 0; iCol < iNumRowCol; ++iCol)
        {
            if (vecMaze[iRow][iCol] == WALL ||
                vecMaze[iRow][iCol] == NSEARCH)
                cout << "-\t" << " ";
            else
                cout << vecMaze[iRow][iCol] << "\t";
        }
        cout << '\n';
    }

    return 0;
}

*/