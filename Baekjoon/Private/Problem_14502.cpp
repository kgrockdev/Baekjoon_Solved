#include "Problem_14502.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_14502::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    vector<vector<int>> vecMaze;
    vector<pair<int, int>> vecEmpty;
    vector<pair<int, int>> vecVirus;

    int iNumRow = { }, iNumCol = { };
    cin >> iNumRow >> iNumCol;

    for (int iRow = 0; iRow < iNumRow; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < iNumCol; ++iCol)
        {
            int iSrc = { };
            cin >> iSrc;

            vecSrc.push_back(iSrc);

            if (iSrc == 0)
                vecEmpty.push_back({ iRow, iCol });
            if (iSrc == 2)
                vecVirus.push_back({ iRow, iCol });
        }

        vecMaze.push_back(vecSrc);
    }

    int iAnswer = { 0 };
    for (int iNodeA = 0; iNodeA < vecEmpty.size(); ++iNodeA)
    {
        for (int iNodeB = iNodeA + 1; iNodeB < vecEmpty.size(); ++iNodeB)
        {
            for (int iNodeC = iNodeB + 1; iNodeC < vecEmpty.size(); ++iNodeC)
            {
                vector<vector<int>> vecMazeSrc(vecMaze);
                vector<pair<int, int>> vecVirusSrc(vecVirus);

                vecMazeSrc[vecEmpty[iNodeA].first][vecEmpty[iNodeA].second] = 1;
                vecMazeSrc[vecEmpty[iNodeB].first][vecEmpty[iNodeB].second] = 1;
                vecMazeSrc[vecEmpty[iNodeC].first][vecEmpty[iNodeC].second] = 1;

                int iSafe = vecEmpty.size() - 3;
                while (vecVirusSrc.size() > 0)
                {
                    pair<int, int> pairNode = vecVirusSrc.back();
                    vecVirusSrc.pop_back();

                    // ╩С
                    if (pairNode.first > 0 &&
                        vecMazeSrc[pairNode.first - 1][pairNode.second] == 0)
                    {
                        --iSafe;
                        vecMazeSrc[pairNode.first - 1][pairNode.second] = 2;
                        vecVirusSrc.push_back({ pairNode.first - 1, pairNode.second });
                    }

                    // го
                    if (pairNode.first < iNumRow - 1 &&
                        vecMazeSrc[pairNode.first + 1][pairNode.second] == 0)
                    {
                        --iSafe;
                        vecMazeSrc[pairNode.first + 1][pairNode.second] = 2;
                        vecVirusSrc.push_back({ pairNode.first + 1, pairNode.second });
                    }

                    // аб
                    if (pairNode.second > 0 &&
                        vecMazeSrc[pairNode.first][pairNode.second - 1] == 0)
                    {
                        --iSafe;
                        vecMazeSrc[pairNode.first][pairNode.second - 1] = 2;
                        vecVirusSrc.push_back({ pairNode.first, pairNode.second - 1 });
                    }

                    // ©Л
                    if (pairNode.second < iNumCol - 1 &&
                        vecMazeSrc[pairNode.first][pairNode.second + 1] == 0)
                    {
                        --iSafe;
                        vecMazeSrc[pairNode.first][pairNode.second + 1] = 2;
                        vecVirusSrc.push_back({ pairNode.first, pairNode.second + 1 });
                    }
                }

                iAnswer = ((iAnswer < iSafe) ? iSafe : iAnswer);
            }
        }
    }

    cout << iAnswer << endl;

    return 0;
}
