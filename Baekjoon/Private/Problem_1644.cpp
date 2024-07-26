#include "Problem_1644.h"

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define NUMMAX 4000010

int CProblem_1644::Solve_Problem()
{
    int iTarget = { };
    cin >> iTarget;

    vector<bool> vecSosu(NUMMAX);
    vecSosu[2] = true;
    vecSosu[3] = true;
    vecSosu[5] = true;
    vecSosu[7] = true;

    for (int iIdx = 11; iIdx < NUMMAX; iIdx += 2)
    {
        if (iIdx % 3 == 0 ||
            iIdx % 5 == 0 ||
            iIdx % 7 == 0)
            continue;

        vecSosu[iIdx] = true;
    }

    for (int iBegin = 11; iBegin < sqrt(NUMMAX); ++iBegin)
    {
        if (vecSosu[iBegin] == false)
            continue;

        for (unsigned long long ullEnd = iBegin * iBegin; ullEnd < NUMMAX; ullEnd += iBegin)
        {
            vecSosu[ullEnd] = false;
        }
    }

    int iAnswer = { };
    
    int iBegin = 2, iEnd = 2;

    while (true)
    {
        if (iBegin > iTarget || iEnd > iTarget)
            break;

        int iSrc = { };
        for (int iSearch = iBegin; iSearch < iEnd + 1; ++iSearch)
        {
            if (vecSosu[iSearch] == true)
                iSrc += iSearch;
        }

        if (iSrc == iTarget)
        {
            ++iAnswer;

            ++iEnd;
            if (iBegin > iTarget || iEnd > iTarget)
                break;

            while (vecSosu[iEnd] != true)
            {
                if (iBegin > iTarget || iEnd > iTarget)
                    break;
                ++iEnd;
            }
        }
        else if (iSrc > iTarget)
        {
            ++iBegin;
            if (iBegin > iTarget || iEnd > iTarget)
                break;

            while (vecSosu[iBegin] != true)
            {
                if (iBegin > iTarget || iEnd > iTarget)
                    break;
                ++iBegin;
            }
        }
        else if (iSrc < iTarget)
        {
            ++iEnd;
            if (iBegin > iTarget || iEnd > iTarget)
                break;

            while (vecSosu[iEnd] != true)
            {
                if (iBegin > iTarget || iEnd > iTarget)
                    break;
                ++iEnd;
            }
        }
    }

    cout << iAnswer << '\n';

    return 0;
}
