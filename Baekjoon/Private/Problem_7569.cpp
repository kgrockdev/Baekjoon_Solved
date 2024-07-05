#include "Problem_7569.h"

#include <list>
#include <vector>
#include <iostream>

using namespace std;

typedef struct tagPosition
{
    int iDay = { };

    int iDim = { };
    int iRow = { };
    int iCol = { };
} POS;

int CProblem_7569::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iX = { }, iY = { }, iZ = { };
    cin >> iX >> iY >> iZ;

    list<POS> lstBFS;
    vector<vector<vector<int>>> vecContainer;
    vecContainer.reserve(iZ);

    for (int iDimension = 0; iDimension < iZ; ++iDimension)
    {
        vector<vector<int>> vecRowSrc;
        vecRowSrc.reserve(iY);
        for (int iRow = 0; iRow < iY; ++iRow)
        {
            vector<int> vecColSrc;
            vecColSrc.reserve(iX);
            for (int iCol = 0; iCol < iX; ++iCol)
            {
                int iSrc = { };
                cin >> iSrc;

                vecColSrc.push_back(iSrc);

                if (iSrc == 1)
                    lstBFS.push_back({ 0, iDimension, iRow, iCol });
            }
            vecRowSrc.push_back(vecColSrc);
        }
        vecContainer.push_back(vecRowSrc);
    }

    int iAnsDay = { };
    while (lstBFS.size() > 0)
    {
        POS tPos = { lstBFS.front() };
        lstBFS.pop_front();

        iAnsDay = tPos.iDay;
        ++tPos.iDay;

        if (tPos.iDim > 0 &&
            vecContainer[tPos.iDim - 1][tPos.iRow][tPos.iCol] == 0)
        {
            vecContainer[tPos.iDim - 1][tPos.iRow][tPos.iCol] = 1;

            POS tPosSrc = { tPos };
            --tPosSrc.iDim;
            lstBFS.push_back(tPosSrc);
        }

        if (tPos.iDim < iZ - 1 &&
            vecContainer[tPos.iDim + 1][tPos.iRow][tPos.iCol] == 0)
        {
            vecContainer[tPos.iDim + 1][tPos.iRow][tPos.iCol] = 1;

            POS tPosSrc = { tPos };
            ++tPosSrc.iDim;
            lstBFS.push_back(tPosSrc);
        }

        if (tPos.iRow > 0 &&
            vecContainer[tPos.iDim][tPos.iRow - 1][tPos.iCol] == 0)
        {
            vecContainer[tPos.iDim][tPos.iRow - 1][tPos.iCol] = 1;

            POS tPosSrc = { tPos };
            --tPosSrc.iRow;
            lstBFS.push_back(tPosSrc);
        }

        if (tPos.iRow < iY - 1 &&
            vecContainer[tPos.iDim][tPos.iRow + 1][tPos.iCol] == 0)
        {
            vecContainer[tPos.iDim][tPos.iRow + 1][tPos.iCol] = 1;

            POS tPosSrc = { tPos };
            ++tPosSrc.iRow;
            lstBFS.push_back(tPosSrc);
        }

        if (tPos.iCol > 0 &&
            vecContainer[tPos.iDim][tPos.iRow][tPos.iCol - 1] == 0)
        {
            vecContainer[tPos.iDim][tPos.iRow][tPos.iCol - 1] = 1;

            POS tPosSrc = { tPos };
            --tPosSrc.iCol;
            lstBFS.push_back(tPosSrc);
        }

        if (tPos.iCol < iX - 1 &&
            vecContainer[tPos.iDim][tPos.iRow][tPos.iCol + 1] == 0)
        {
            vecContainer[tPos.iDim][tPos.iRow][tPos.iCol + 1] = 1;

            POS tPosSrc = { tPos };
            ++tPosSrc.iCol;
            lstBFS.push_back(tPosSrc);
        }
    }

    for (auto iterZ : vecContainer)
    {
        for (auto iterY : iterZ)
        {
            for (auto iterX : iterY)
            {
                if (iterX == 0)
                {
                    cout << -1 << '\n';

                    return 0;
                }
            }
        }
    }

    cout << iAnsDay << '\n';

    return 0;
}
