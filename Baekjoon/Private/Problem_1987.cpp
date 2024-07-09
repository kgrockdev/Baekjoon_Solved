#include "Problem_1987.h"

#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct tagElem
{
    int iRow = { };
    int iCol = { };

    bitset<26> bitTraj;
} ELEM;

int CProblem_1987::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumRow = { }, iNumCol = { };
    cin >> iNumRow >> iNumCol;

    vector<vector<char>> vecMaze;
    vecMaze.reserve(iNumRow);

    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        vector<char> vecSrc;
        vecSrc.reserve(iNumCol);

        for (int iCol = 0; iCol < iNumCol; ++iCol)
        {
            char chSrc = { };
            cin >> chSrc;

            vecSrc.push_back(chSrc);
        }

        vecMaze.push_back(vecSrc);
    }

    vector<ELEM> vecDFS;
    vecDFS.push_back({ 0, 0 });
    vecDFS.back().bitTraj.set(vecMaze[0][0] - 'A');

    int iAnswer = { };
    while (vecDFS.size() > 0)
    {
        ELEM tElem = vecDFS.back();
        vecDFS.pop_back();
        
        iAnswer = (iAnswer > tElem.bitTraj.count()) ? iAnswer : tElem.bitTraj.count();
        if (iAnswer == 26)
            break;
    
        if (tElem.iRow > 0 &&
            !tElem.bitTraj.test(vecMaze[tElem.iRow - 1][tElem.iCol] - 'A'))
        {
            ELEM tElemSrc = tElem;
            --tElemSrc.iRow;
            tElemSrc.bitTraj.set(vecMaze[tElemSrc.iRow][tElemSrc.iCol] - 'A');

            vecDFS.push_back(tElemSrc);
        }
    
        if (tElem.iRow < iNumRow - 1 &&
            !tElem.bitTraj.test(vecMaze[tElem.iRow + 1][tElem.iCol] - 'A'))
        {
            ELEM tElemSrc = tElem;
            ++tElemSrc.iRow;
            tElemSrc.bitTraj.set(vecMaze[tElemSrc.iRow][tElemSrc.iCol] - 'A');
    
            vecDFS.push_back(tElemSrc);
        }
    
        if (tElem.iCol > 0 &&
            !tElem.bitTraj.test(vecMaze[tElem.iRow][tElem.iCol - 1] - 'A'))
        {
            ELEM tElemSrc = tElem;
            --tElemSrc.iCol;
            tElemSrc.bitTraj.set(vecMaze[tElemSrc.iRow][tElemSrc.iCol] - 'A');
    
            vecDFS.push_back(tElemSrc);
        }
    
        if (tElem.iCol < iNumCol - 1 &&
            !tElem.bitTraj.test(vecMaze[tElem.iRow][tElem.iCol + 1] - 'A'))
        {
            ELEM tElemSrc = tElem;
            ++tElemSrc.iCol;
            tElemSrc.bitTraj.set(vecMaze[tElemSrc.iRow][tElemSrc.iCol] - 'A');
    
            vecDFS.push_back(tElemSrc);
        }
    }

    cout << iAnswer << '\n';

    return 0;
}
