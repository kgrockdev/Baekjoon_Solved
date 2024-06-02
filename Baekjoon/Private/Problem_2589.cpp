#include "Problem_2589.h"

#include <set>
#include <vector>
#include <iostream>

#define INT_MIN     (-2147483647 - 1)
#define INT_MAX       2147483647

using namespace std;

int CProblem_2589::Solve_Problem()
{
    int iNumRow = { }, iNumCol = { };
    cin >> iNumRow >> iNumCol;

    char chSrc = { };
    vector<vector<bool>> vecMaze;
    vector<vector<int>> vecMazeWeight;
    set<pair<int, int>> setNode;
    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        vector<bool> vecSrc;
        vector<int> vecSrcWeight;
        for (int iCol = 0; iCol < iNumCol; ++iCol)
        {
            cin >> chSrc;

            if (chSrc == 'W')
            {
                vecSrc.push_back(false);
                vecSrcWeight.push_back(INT_MIN);
            }
            else
            {
                vecSrc.push_back(true);
                vecSrcWeight.push_back(INT_MAX);
                setNode.emplace(pair<int, int>{ iRow, iCol });
            }
        }
        vecMaze.push_back(vecSrc);
        vecMazeWeight.push_back(vecSrcWeight);
    }

    while (setNode.size() > 0)
    {
        pair<int, int> pair = *setNode.begin();
        setNode.erase(setNode.begin());


    }

    return 0;
}
