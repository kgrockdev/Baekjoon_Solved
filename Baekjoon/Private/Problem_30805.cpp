#include "Problem_30805.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_30805::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumSeqA = { }, iNumSeqB = { };
    vector<int> vecSeqA;
    vector<int> vecSeqB;

    cin >> iNumSeqA;
    for (int iSeq = 0; iSeq < iNumSeqA; ++iSeq)
    {
        int iSrc = { };
        cin >> iSrc;

        vecSeqA.push_back(iSrc);
    }

    cin >> iNumSeqB;
    for (int iSeq = 0; iSeq < iNumSeqB; ++iSeq)
    {
        int iSrc = { };
        cin >> iSrc;

        vecSeqB.push_back(iSrc);
    }

    vector<vector<int>> vecLCS;
    for (int iRow = 0; iRow < iNumSeqB + 1; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < iNumSeqA + 1; ++iCol)
        {
            vecSrc.push_back(0);
        }
        vecLCS.push_back(vecSrc);
    }

    for (int iRow = 1; iRow < iNumSeqB + 1; ++iRow)
    {
        for (int iCol = 1; iCol < iNumSeqA + 1; ++iCol)
        {
            if (vecSeqB[iRow - 1] == vecSeqA[iCol - 1])
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

    vector<int> vecSubsequence;
    int iRow = { iNumSeqB }, iCol = { iNumSeqA };

    while (true)
    {
        if (vecLCS[iRow][iCol] == vecLCS[iRow - 1][iCol])
        {
            iRow = iRow - 1;
            continue;
        }

        if (vecLCS[iRow][iCol] == vecLCS[iRow][iCol - 1])
        {
            iCol = iCol - 1;
            continue;
        }

        iRow = iRow - 1;
        iCol = iCol - 1;
        vecSubsequence.push_back(vecSeqA[iCol]);

        if (vecLCS[iRow][iCol] == 0)
            break;
    }

    reverse(vecSubsequence.begin(), vecSubsequence.end());
    for (auto iter = vecSubsequence.begin(); ;)
    {
        auto nextIter = iter;
        ++nextIter;

        if (nextIter == vecSubsequence.end())
            break;

        if (*iter < *nextIter)
            iter = vecSubsequence.erase(iter);
        else
            ++iter;
    }

    cout << vecSubsequence.size() << '\n';
    for (auto iter : vecSubsequence)
        cout << iter << " ";
    cout << '\n';

    return 0;
}
