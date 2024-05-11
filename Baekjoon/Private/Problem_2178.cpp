#include "Problem_2178.h"

#include <list>
#include <string>
#include <iostream>

using namespace std;

#define PAIR        pair<int, int>
#define SHRT_MAX    32767

int CProblem_2178::Solve_Problem()
{
    int iNumRow = { }, iNumCol = { };
    cin >> iNumRow >> iNumCol;

    short** arrMaze = new short*[iNumRow];
    for (int iIndex = 0; iIndex < iNumRow; ++iIndex)
    {
        arrMaze[iIndex] = new short[iNumCol];
    }
    
    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        string strRoute = { };
        cin >> strRoute;

        for (int iCol = 0; iCol < iNumCol; ++iCol)
            arrMaze[iRow][iCol] = (strRoute[iCol] == '1') ? SHRT_MAX : -1;
    }
    arrMaze[0][0] = 0;

    list<PAIR> listSearch;
    listSearch.push_back(PAIR { 0, 0 });

    while (listSearch.size() > 0)
    {
        PAIR pairSrc = listSearch.front();
        listSearch.pop_front();

        int iBitMask = 0b0000;
        if (pairSrc.first - 1 >= 0)
            iBitMask |= 0b0001;
        if (pairSrc.first + 1 < iNumRow)
            iBitMask |= 0b0010;
        if (pairSrc.second - 1 >= 0)
            iBitMask |= 0b0100;
        if (pairSrc.second + 1 < iNumCol)
            iBitMask |= 0b1000;

        if (((iBitMask & 0b0001) != 0b0000) && 
            (arrMaze[pairSrc.first - 1][pairSrc.second] != -1) && 
            (arrMaze[pairSrc.first - 1][pairSrc.second] == SHRT_MAX))
        {
            arrMaze[pairSrc.first - 1][pairSrc.second]
                = min(arrMaze[pairSrc.first - 1][pairSrc.second], static_cast<short>(arrMaze[pairSrc.first][pairSrc.second] + 1));

            listSearch.push_back(PAIR{ pairSrc.first - 1, pairSrc.second });
        }
        if (((iBitMask & 0b0010) != 0b0000) && 
            (arrMaze[pairSrc.first + 1][pairSrc.second] != -1) &&
            (arrMaze[pairSrc.first + 1][pairSrc.second] == SHRT_MAX))
        {
            arrMaze[pairSrc.first + 1][pairSrc.second]
                = min(arrMaze[pairSrc.first + 1][pairSrc.second], static_cast<short>(arrMaze[pairSrc.first][pairSrc.second] + 1));

            listSearch.push_back(PAIR{ pairSrc.first + 1, pairSrc.second });
        }
        if (((iBitMask & 0b0100) != 0b0000) && 
            (arrMaze[pairSrc.first][pairSrc.second - 1] != -1) &&
            (arrMaze[pairSrc.first][pairSrc.second - 1] == SHRT_MAX))
        {
            arrMaze[pairSrc.first][pairSrc.second - 1]
                = min(arrMaze[pairSrc.first][pairSrc.second - 1], static_cast<short>(arrMaze[pairSrc.first][pairSrc.second] + 1));

            listSearch.push_back(PAIR{ pairSrc.first, pairSrc.second - 1 });
        }
        if (((iBitMask & 0b1000) != 0b0000) && 
            (arrMaze[pairSrc.first][pairSrc.second + 1] != -1) &&
            (arrMaze[pairSrc.first][pairSrc.second + 1] == SHRT_MAX))
        {
            arrMaze[pairSrc.first][pairSrc.second + 1]
                = min(arrMaze[pairSrc.first][pairSrc.second + 1], static_cast<short>(arrMaze[pairSrc.first][pairSrc.second] + 1));

            listSearch.push_back(PAIR{ pairSrc.first, pairSrc.second + 1 });
        }
    }

    cout << arrMaze[iNumRow - 1][iNumCol - 1] + 1 << '\n';

    for (int iIndex = 0; iIndex < iNumRow; ++iIndex)
        delete[] arrMaze[iIndex];
    delete[] arrMaze;

    return 0;
}
