#include "Problem_1967.h"

#include <map>
#include <vector>
#include <iostream>

using namespace std;

typedef struct tagTreeElement
{
    int iLeft = { };
    int iLWeight = { };

    int iRight = { };
    int iRWeight = { };
} ELEM;

typedef struct tagTreeWeight
{
    int iSearch = { };
    int iAccWeight = { };

    vector<tagTreeWeight> vecTraj;
} TWEIGHT;

int CProblem_1967::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    map<int, ELEM> mapTree;

    int iNumElem = { };
    cin >> iNumElem;

    for (int iElem = 0; iElem < iNumElem; ++iElem)
    {
        ELEM tElem = { };
        mapTree.emplace(iElem + 1, tElem);
    }

    for (int iElem = 0; iElem < iNumElem - 1; ++iElem)
    {
        int iParent = { }, iChild = { }, iWeight = { };
        cin >> iParent >> iChild >> iWeight;

        if (mapTree.find(iParent)->second.iLeft == 0)
        {
            mapTree.find(iParent)->second.iLeft = iChild;
            mapTree.find(iParent)->second.iLWeight = iWeight;
        }
        else
        {
            mapTree.find(iParent)->second.iRight = iChild;
            mapTree.find(iParent)->second.iRWeight = iWeight;
        }
    }

    int iFirstElem = { }, iFWeight = { };
    vector<TWEIGHT> vecFTraj;

    vector<TWEIGHT> vecDFS; vecDFS.push_back(TWEIGHT{ 1, 0 });
    while (vecDFS.size() > 0)
    {
        TWEIGHT tWeight = vecDFS.back();
        vecDFS.pop_back();
        tWeight.vecTraj.push_back(tWeight);

        if (iFWeight < tWeight.iAccWeight)
        {
            iFirstElem = tWeight.iSearch;
            iFWeight = tWeight.iAccWeight;
            vecFTraj = tWeight.vecTraj;
        }

        if (mapTree.find(tWeight.iSearch)->second.iLeft != 0)
        {
            vecDFS.push_back(TWEIGHT{ mapTree.find(tWeight.iSearch)->second.iLeft,
                tWeight.iAccWeight + mapTree.find(tWeight.iSearch)->second.iLWeight, tWeight.vecTraj });
        }

        if (mapTree.find(tWeight.iSearch)->second.iRight != 0)
        {
            vecDFS.push_back(TWEIGHT{ mapTree.find(tWeight.iSearch)->second.iRight,
                tWeight.iAccWeight + mapTree.find(tWeight.iSearch)->second.iRWeight, tWeight.vecTraj });
        }
    }

    int iSecondElem = { }, iSWeight = { }, iAccSWeight = { };
    while (vecFTraj.size() > 1)
    {
        TWEIGHT tWeight = vecFTraj.back();
        vecFTraj.pop_back();

        iAccSWeight += tWeight.iAccWeight - vecFTraj.back().iAccWeight;

        vector<TWEIGHT> vecDFS;
        TWEIGHT tSearchSrc = { };
        tSearchSrc.iAccWeight = iAccSWeight;

        if (mapTree.find(vecFTraj.back().iSearch)->second.iLeft == tWeight.iSearch)
        {
            tSearchSrc.iSearch = mapTree.find(vecFTraj.back().iSearch)->second.iRight;
            tSearchSrc.iAccWeight += mapTree.find(vecFTraj.back().iSearch)->second.iRWeight;
        }
        else
        {
            tSearchSrc.iSearch = mapTree.find(vecFTraj.back().iSearch)->second.iLeft;
            tSearchSrc.iAccWeight += mapTree.find(vecFTraj.back().iSearch)->second.iLWeight;
        }
        
        vecDFS.push_back(tSearchSrc);

        while (vecDFS.size() > 0)
        {
            TWEIGHT tWeight = vecDFS.back();
            vecDFS.pop_back();

            if (iSWeight < tWeight.iAccWeight)
            {
                iSecondElem = tWeight.iSearch;
                iSWeight = tWeight.iAccWeight;
            }

            if (mapTree.find(tWeight.iSearch)->second.iLeft != 0)
            {
                vecDFS.push_back(TWEIGHT{ mapTree.find(tWeight.iSearch)->second.iLeft,
                    tWeight.iAccWeight + mapTree.find(tWeight.iSearch)->second.iLWeight, tWeight.vecTraj });
            }

            if (mapTree.find(tWeight.iSearch)->second.iRight != 0)
            {
                vecDFS.push_back(TWEIGHT{ mapTree.find(tWeight.iSearch)->second.iRight,
                    tWeight.iAccWeight + mapTree.find(tWeight.iSearch)->second.iRWeight, tWeight.vecTraj });
            }
        }
    }

    cout << iSWeight << endl;

    return 0;
}