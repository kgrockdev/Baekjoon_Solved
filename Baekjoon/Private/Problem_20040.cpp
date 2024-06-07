#include "Problem_20040.h"

#include <iostream>
#include <unordered_map>

using namespace std;

bool Union_20040(unordered_map<int, int>& mapUnionFind, int iSrc, int iDst)
{
    int iUnionSrc = { iSrc };
    while (iUnionSrc != mapUnionFind.find(iUnionSrc)->second)
        iUnionSrc = mapUnionFind.find(iUnionSrc)->second;

    int iUnionDst = { iDst };
    while (iUnionDst != mapUnionFind.find(iUnionDst)->second)
        iUnionDst = mapUnionFind.find(iUnionDst)->second;

    if (iUnionDst == iUnionSrc)
        return true;
    else
    {
        if (iUnionDst < iUnionSrc)
            mapUnionFind.find(iUnionSrc)->second = iUnionDst;
        else
            mapUnionFind.find(iUnionDst)->second = iUnionSrc;

        return false;
    }
}

int CProblem_20040::Solve_Problem()
{
    unordered_map<int, int> mapUnionFind;

    int iNumNode = { }, iNumPlay = { };
    cin >> iNumNode >> iNumPlay;

    for (int iNode = 0; iNode < iNumNode; ++iNode)
        mapUnionFind.emplace(iNode, iNode);

    int iRes = { -1 };
    for (int iPlay = 0; iPlay < iNumPlay; ++iPlay)
    {
        int iSrc = { }, iDst = { };
        cin >> iSrc >> iDst;

        if (iRes == -1 && Union_20040(mapUnionFind, iSrc, iDst) == true)
            iRes = iPlay + 1;
    }

    if (iRes == -1)
        cout << "0" << endl;
    else
        cout << iRes << endl;

    return 0;
}
