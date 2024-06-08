#include "Problem_28456.h"

#include <list>
#include <vector>
#include <iostream>

using namespace std;

int CProblem_28456::Solve_Problem()
{
    int iNumArray = { };
    cin >> iNumArray;

    vector<list<int>> vecArray;
    for (int iRow = 0; iRow < iNumArray; ++iRow)
    {
        int iSrc = { };
        list<int> lstSrc;
        for (int iCol = 0; iCol < iNumArray; ++iCol)
        {
            cin >> iSrc;
            lstSrc.push_back(iSrc);
        }
        vecArray.push_back(lstSrc);
    }

    int iNumCalc = { };
    cin >> iNumCalc;

    for (int iCalc = 0; iCalc < iNumCalc; ++iCalc)
    {
        int iNum = { };
        cin >> iNum;

        if (iNum == 1)
        {
            int iSelRow = { };
            cin >> iSelRow;

            iSelRow -= 1;

            vecArray[iSelRow].push_front(vecArray[iSelRow].back());
            vecArray[iSelRow].pop_back();
        }
        else
        {
            vector<list<int>> vecSrc;
            for (int iCol = 0; iCol < iNumArray; ++iCol)
            {
                list<int> lstSrc;
                for (int iRow = 0; iRow < iNumArray; ++iRow)
                {
                    auto iter = vecArray[iNumArray - iRow - 1].begin();
                    advance(iter, iCol);

                    lstSrc.push_back(*iter);
                }

                vecSrc.push_back(lstSrc);
            }

            vecArray = vecSrc;
        }
    }

    for (int iRow = 0; iRow < iNumArray; ++iRow)
    {
        for (auto colIter : vecArray[iRow])
            cout << colIter << " ";

        cout << '\n';
    }

    return 0;
}
