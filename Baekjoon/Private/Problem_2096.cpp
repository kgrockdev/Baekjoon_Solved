#include "Problem_2096.h"

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

#define INT_MAX       2147483647
#define INT_MIN     (-2147483647 - 1)

using namespace std;

typedef struct tagElement2096
{
    int iX = { };
    int iY = { };
    int iTotal = { };
} ELEM2096;

int CProblem_2096::Solve_Problem()
{
    int iNumLine = { }, iSrc = { };
    cin >> iNumLine;

    vector<unsigned long long> vecMaze;             vecMaze.reserve(3);
    vector<unsigned long long> vecBigMaze;          vecBigMaze.reserve(3);
    vector<unsigned long long> vecPrevBigMaze;      vecPrevBigMaze.reserve(3);
    vector<unsigned long long> vecShortMaze;        vecShortMaze.reserve(3);
    vector<unsigned long long> vecPrevShortMaze;    vecPrevShortMaze.reserve(3);

    if (iNumLine == 1)
    {
        for (int iCol = 0; iCol < 3; ++iCol)
        {
            cin >> iSrc;

            vecBigMaze.push_back(iSrc);
            vecShortMaze.push_back(iSrc);
        }
    }
    else
    {
        for (int iCol = 0; iCol < 3; ++iCol)
        {
            cin >> iSrc;
            vecPrevBigMaze.push_back(iSrc);
            vecPrevShortMaze.push_back(iSrc);

            vecBigMaze.push_back(0);
            vecShortMaze.push_back(0);
        }

        for (int iLine = 1; iLine < iNumLine; ++iLine)
        {
            vecMaze.clear();
            for (int iCol = 0; iCol < 3; ++iCol)
            {
                cin >> iSrc;
                vecMaze.push_back(iSrc);
            }

            // Big
            vecBigMaze[0] = vecMaze[0] + max(vecPrevBigMaze[0], vecPrevBigMaze[1]);
            vecBigMaze[1] = vecMaze[1] + max({ vecPrevBigMaze[0], vecPrevBigMaze[1], vecPrevBigMaze[2] });
            vecBigMaze[2] = vecMaze[2] + max(vecPrevBigMaze[1], vecPrevBigMaze[2]);

            // Short
            vecShortMaze[0] = vecMaze[0] + min(vecPrevShortMaze[0], vecPrevShortMaze[1]);
            vecShortMaze[1] = vecMaze[1] + min({ vecPrevShortMaze[0], vecPrevShortMaze[1], vecPrevShortMaze[2] });
            vecShortMaze[2] = vecMaze[2] + min(vecPrevShortMaze[1], vecPrevShortMaze[2]);

            vecPrevBigMaze = vecBigMaze;
            vecPrevShortMaze = vecShortMaze;
        }
    }

    sort(vecBigMaze.begin(), vecBigMaze.end());
    sort(vecShortMaze.begin(), vecShortMaze.end());

    cout << vecBigMaze[2] << " " << vecShortMaze[0] << endl;

    return 0;
}