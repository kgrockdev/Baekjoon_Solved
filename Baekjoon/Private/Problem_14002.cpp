#include "Problem_14002.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int CProblem_14002::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    wstring strA = { }, strB = { };
    getline(wcin, strA);
    getline(wcin, strB);

    vector<vector<int>> vecLCS;
    for (int iRow = 0; iRow < strA.size() / 3 + 1; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < strB.size() / 3 + 1; ++iCol)
            vecSrc.push_back(0);

        vecLCS.push_back(vecSrc);
    }

    for (int iRow = 1; iRow < strA.size() / 3 + 1; ++iRow)
    {
        for (int iCol = 1; iCol < strB.size() / 3 + 1; ++iCol)
        {
            if (strA.substr((iRow - 1) * 3, 3) == strB.substr((iCol - 1) * 3, 3))
            {
                vecLCS[iRow][iCol] = vecLCS[iRow - 1][iCol - 1] + 1;
            }
            else
            {
                vecLCS[iRow][iCol] =
                    (vecLCS[iRow - 1][iCol] > vecLCS[iRow][iCol - 1]) ?
                    vecLCS[iRow - 1][iCol] : vecLCS[iRow][iCol - 1];
            }
        }
    }

    cout << vecLCS[strA.size() / 3][strB.size() / 3] << '\n';

    return 0;
}
