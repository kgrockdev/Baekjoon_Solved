#include "Problem_15686.h"

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

#define INT_MAX       2147483647

using namespace std;

int CProblem_15686::Solve_Problem()
{
    int iNumRowCol = { }, iNumStore = { };
    cin >> iNumRowCol >> iNumStore;

    vector<pair<int, int>> vecHome;
    vector<pair<int, int>> vecStore;
    vector<vector<int>> vecStreet;

    for (int iRow = 0; iRow < iNumRowCol; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < iNumRowCol; ++iCol)
        {
            int iSrc = { };
            cin >> iSrc;

            vecSrc.push_back(iSrc);

            if (iSrc == 1)
                vecHome.push_back({ iRow, iCol });
            else if (iSrc == 2)
                vecStore.push_back({ iRow, iCol });
        }

        vecStreet.push_back(vecSrc);
    }

    vector<int> vecPermutation;
    
    for (int iIndex = iNumStore; iIndex < vecStore.size(); ++iIndex)
        vecPermutation.push_back(0);

    for (int iIndex = 0; iIndex < iNumStore; ++iIndex)
        vecPermutation.push_back(1);

    int iDist = { INT_MAX };
    do
    {
        int iSrcDist = { };

        vector<pair<int, int>> vecPermStore;
        for (int iIndex = 0; iIndex < vecStore.size(); ++iIndex)
        {
            if (vecPermutation[iIndex] == 1)
                vecPermStore.push_back(vecStore[iIndex]);
        }

        for (auto& homeIter : vecHome)
        {
            int iMinDist = { INT_MAX };
            for (auto& storeIter : vecPermStore)
            {
                iMinDist = 
                    min(iMinDist, abs(homeIter.first - storeIter.first) + abs(homeIter.second - storeIter.second));
            }

            iSrcDist += iMinDist;
        }

        iDist = min(iDist, iSrcDist);

    } while (next_permutation(vecPermutation.begin(), vecPermutation.end()));

    cout << iDist << '\n';

    return 0;
}
