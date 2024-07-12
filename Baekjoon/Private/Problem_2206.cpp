#include "Problem_2206.h"

#include <queue>
#include <string>
#include <vector>
#include <iostream>

#define INF 1000000000

using namespace std;

typedef struct tagRoute
{
    int iRow = { };
    int iCol = { };

    int iBreak = { };
    int iNumRoute = { };

    bool operator()(const tagRoute& tRouteA, const tagRoute& tRouteB)
    {
        return tRouteA.iNumRoute > tRouteB.iNumRoute;
    }
} ROUTE;

int CProblem_2206::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumRow = { }, iNumCol = { };
    cin >> iNumRow >> iNumCol;

    vector<vector<int>> vecMaze;
    vector<vector<int>> vecWeight[2];

    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        string strSrc;
        cin >> strSrc;

        vector<int> vecSrc;
        vector<int> vecWeightSrc;
        for (int iCol = 0; iCol < iNumCol; ++iCol)
        {
            vecSrc.push_back(strSrc[iCol] - '0');
            vecWeightSrc.push_back(INF);
        }

        vecMaze.push_back(vecSrc);
        vecWeight[0].push_back(vecWeightSrc);
        vecWeight[1].push_back(vecWeightSrc);
    }

    priority_queue<ROUTE, vector<ROUTE>, ROUTE> pqContainer;
    pqContainer.emplace(ROUTE{ 0, 0, 0, 1 });
    vecWeight[0][0][0] = 1;
    vecWeight[1][0][0] = 1;

    
    while (pqContainer.size() > 0)
    {
        ROUTE tRoute = pqContainer.top();
        pqContainer.pop();

        // TOP
        if (tRoute.iRow > 0)
        {
            if (vecMaze[tRoute.iRow - 1][tRoute.iCol] == 0)
            {
                if (vecWeight[0][tRoute.iRow - 1][tRoute.iCol] > tRoute.iNumRoute + 1)
                {
                    ROUTE tRouteSrc = tRoute;
                    tRouteSrc.iRow -= 1;
                    tRouteSrc.iNumRoute += 1;

                    pqContainer.emplace(tRouteSrc);
                    vecWeight[0][tRouteSrc.iRow][tRouteSrc.iCol] = tRouteSrc.iNumRoute;
                }
            }
            else
            {
                if (tRoute.iBreak < 1)
                {

                }

                if (vecWeight[1][tRoute.iRow - 1][tRoute.iCol] > tRoute.iNumRoute + 1)
                {
                    ROUTE tRouteSrc = tRoute;
                    tRouteSrc.iRow -= 1;
                    tRouteSrc.iNumRoute += 1;

                    pqContainer.emplace(tRouteSrc);
                    vecWeight[0][tRouteSrc.iRow][tRouteSrc.iCol] = tRouteSrc.iNumRoute;
                }
            }

            if (tRoute.iBreak == 0 ||
                (tRoute.iBreak == 1 && vecMaze[tRoute.iRow - 1][tRoute.iCol] != 1))
            {
                ROUTE tRouteSrc = tRoute;
                tRouteSrc.iRow -= 1;
                tRouteSrc.iNumRoute += 1;

                if (vecMaze[tRoute.iRow - 1][tRoute.iCol] == 1)
                    tRouteSrc.iBreak += 1;

                pqContainer.emplace(tRouteSrc);
                // vecWeight[tRouteSrc.iRow][tRouteSrc.iCol] = tRouteSrc.iNumRoute;
            }
        }

        /*
        
         &&
            vecWeight[tRoute.iRow - 1][tRoute.iCol] > tRoute.iNumRoute + 1
        
        */

        // // BOTTOM
        // if (tRoute.iRow < iNumRow - 1 &&
        //     vecWeight[tRoute.iRow + 1][tRoute.iCol] > tRoute.iNumRoute + 1)
        // {
        //     if (tRoute.iBreak == 0 ||
        //         (tRoute.iBreak == 1 && vecMaze[tRoute.iRow + 1][tRoute.iCol] != 1))
        //     {
        //         ROUTE tRouteSrc = tRoute;
        //         tRouteSrc.iRow += 1;
        //         tRouteSrc.iNumRoute += 1;
        // 
        //         if (vecMaze[tRoute.iRow + 1][tRoute.iCol] == 1)
        //             tRouteSrc.iBreak += 1;
        // 
        //         pqContainer.emplace(tRouteSrc);
        //         vecWeight[tRouteSrc.iRow][tRouteSrc.iCol] = tRouteSrc.iNumRoute;
        //     }
        // }
        // 
        // // LEFT
        // if (tRoute.iCol > 0 &&
        //     vecWeight[tRoute.iRow][tRoute.iCol - 1] > tRoute.iNumRoute + 1)
        // {
        //     if (tRoute.iBreak == 0 ||
        //         (tRoute.iBreak == 1 && vecMaze[tRoute.iRow][tRoute.iCol - 1] != 1))
        //     {
        //         ROUTE tRouteSrc = tRoute;
        //         tRouteSrc.iCol -= 1;
        //         tRouteSrc.iNumRoute += 1;
        // 
        //         if (vecMaze[tRoute.iRow][tRoute.iCol - 1] == 1)
        //             tRouteSrc.iBreak += 1;
        // 
        //         pqContainer.emplace(tRouteSrc);
        //         vecWeight[tRouteSrc.iRow][tRouteSrc.iCol] = tRouteSrc.iNumRoute;
        //     }
        // }
        // 
        // // RIGHT
        // if (tRoute.iCol < iNumCol - 1 &&
        //     vecWeight[tRoute.iRow][tRoute.iCol + 1] > tRoute.iNumRoute + 1)
        // {
        //     if (tRoute.iBreak == 0 ||
        //         (tRoute.iBreak == 1 && vecMaze[tRoute.iRow][tRoute.iCol + 1] != 1))
        //     {
        //         ROUTE tRouteSrc = tRoute;
        //         tRouteSrc.iCol += 1;
        //         tRouteSrc.iNumRoute += 1;
        // 
        //         if (vecMaze[tRoute.iRow][tRoute.iCol + 1] == 1)
        //             tRouteSrc.iBreak += 1;
        // 
        //         pqContainer.emplace(tRouteSrc);
        //         vecWeight[tRouteSrc.iRow][tRouteSrc.iCol] = tRouteSrc.iNumRoute;
        //     }
        // }
    }

    // if (vecWeight[iNumRow - 1][iNumCol - 1] == INF)
    //     cout << -1 << '\n';
    // else
    //     cout << vecWeight[iNumRow - 1][iNumCol - 1] << '\n';

    return 0;
}