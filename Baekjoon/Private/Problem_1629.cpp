#include "Problem_1629.h"

#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int CProblem_1629::Solve_Problem()
{
    int iA = { }, iB = { }, iC = { };
    cin >> iA >> iB >> iC;

    unordered_set<int> setContainer;
    unordered_map<int, int> mapContainer;

    int iIndex = 0, iLoop = { };
    unsigned long long ullSrc = { 1 };
    for (; iIndex < iB; ++iIndex)
    {
        ullSrc *= iA;
        ullSrc %= iC;

        if (setContainer.find(ullSrc) == setContainer.end())
        {
            setContainer.emplace(ullSrc);
            mapContainer.emplace(iIndex, ullSrc);
        }
        else
        {
            for (auto& iter : mapContainer)
            {
                if (iter.second == ullSrc)
                {
                    iLoop = iter.first;
                    break;
                }
            }
            break;
        }
    }

    if (iIndex == iB)
    {
        cout << ullSrc << endl;
    }
    else
    {
        int iDigit = { iB };
        iDigit -= iLoop;
        iDigit %= (iIndex - iLoop);
        iDigit -= 1;
        if (iDigit < 0)
            iDigit = (iIndex - iLoop - 1);

        cout << mapContainer.find(iLoop + iDigit)->second << endl;
    }

    return 0;
}
