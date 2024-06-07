#include "Problem_1976.h"

#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void Union_1976(unordered_map<int, int>& mapUnionFind, unordered_set<int> setUnion, int iRootCity)
{
    for (auto iter : setUnion)
    {
        int iSrc = { iRootCity };
        while (iSrc != mapUnionFind.find(iSrc)->second)
            iSrc = mapUnionFind.find(iSrc)->second;

        int iDst = { iter };
        while (iDst != mapUnionFind.find(iDst)->second)
            iDst = mapUnionFind.find(iDst)->second;

        if (iSrc < iDst)
            mapUnionFind.find(iDst)->second = iSrc;
        else
            mapUnionFind.find(iSrc)->second = iDst;
    }
}

bool Find_1976(unordered_map<int, int>& mapUnionFind, unordered_set<int> setFind)
{
    for (auto iter = setFind.begin(); ;)
    {
        int iSrc = { *iter++ };
        while (iSrc != mapUnionFind.find(iSrc)->second)
            iSrc = mapUnionFind.find(iSrc)->second;

        if (iter == setFind.end())
            break;

        int iDst = { *iter };
        while (iDst != mapUnionFind.find(iDst)->second)
            iDst = mapUnionFind.find(iDst)->second;

        if (iSrc != iDst)
            return false;
    }

    return true;
}

int CProblem_1976::Solve_Problem()
{
    unordered_map<int, int> mapUnionFind;

    int iNumCity = { }, iNumTravel = { };
    cin >> iNumCity >> iNumTravel;

    for (int iIndex = 0; iIndex < iNumCity; ++iIndex)
        mapUnionFind.emplace(iIndex, iIndex);

    for (int iCity = 0; iCity < iNumCity; ++iCity)
    {
        unordered_set<int> setUnion;
        for (int iIndex = 0; iIndex < iNumCity; ++iIndex)
        {
            int iSrc = { };
            cin >> iSrc;

            if (iSrc == 1)
                setUnion.emplace(iIndex);
        }

        Union_1976(mapUnionFind, setUnion, iCity);
    }

    unordered_set<int> setFind;
    for (int iCity = 0; iCity < iNumTravel; ++iCity)
    {
        int iSrc = { };
        cin >> iSrc;

        setFind.emplace(iSrc - 1);
    }

    cout << ((Find_1976(mapUnionFind, setFind) == true) ? "YES" : "NO") << endl;

    return 0;
}
