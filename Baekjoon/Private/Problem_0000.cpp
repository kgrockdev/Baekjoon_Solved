#include "Problem_0000.h"

#include <vector>

#include <iostream>

using namespace std;

int CProblem_0000::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iN = { }, iK = { };
    cin >> iN >> iK;

    vector<vector<int>> vecContainer;

    for (int iRow = 0; iRow < iN; ++iRow)
    {
        vector<int> vecSrc;
        for (int iCol = 0; iCol < iN; ++iCol)
        {
            int iSrc = { };
            cin >> iSrc;

            vecSrc.push_back(iSrc);
        }
        vecContainer.push_back(vecSrc);
    }

    int iAnswer = { };
    int iRow = { 0 }, iCol = { 0 }, iDir = { 0 };
    for (int iQus = 0; iQus < iK; ++iQus)
    {
        char chSrc = { };
        cin >> chSrc;

        if (chSrc == 'F')
        {
            switch (iDir)
            {
            case 0:
                iRow += 1;
                break;
            case 1:
                iCol += 1;
                break;
            case 2:
                iRow -= 1;
                break;
            case 3:
                iCol -= 1;
                break;
            }

            iAnswer += vecContainer[iRow][iCol];
        }
        else
        {
            iDir = (iDir + 1) % 4;
        }
    }

    cout << iAnswer << '\n';

    return 0;

	return 0;
}
