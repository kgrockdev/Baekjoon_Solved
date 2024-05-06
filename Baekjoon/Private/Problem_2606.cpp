#include "Problem_2606.h"

#include <set>
#include <vector>
#include <iostream>

using namespace std;

int CProblem_2606::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    set<int> setComputers;
    int arrComputerAdjList[100][100] = { };

    int iNumComputer = { }, iNumConnect = { };
    cin >> iNumComputer >> iNumConnect;

    int iHost = { }, iGuest = { };
    for (int iIndex = 0; iIndex < iNumConnect; ++iIndex)
    {
        cin >> iHost >> iGuest;

        arrComputerAdjList[iHost - 1][iGuest - 1] = 1;
        arrComputerAdjList[iGuest - 1][iHost - 1] = 1;
    }

    int arrSearchedList[100] = { };
    vector<int> vecStack; vecStack.push_back(0);

    while (vecStack.size() > 0)
    {
        int iBase = vecStack.back();
        vecStack.pop_back();

        arrSearchedList[iBase] = 1;
        setComputers.emplace(iBase);

        for (int iIndex = 0; iIndex < iNumComputer; ++iIndex)
        {
            if (arrComputerAdjList[iBase][iIndex] == 1 && arrSearchedList[iIndex] == 0)
                vecStack.push_back(iIndex);
        }
    }

    cout << setComputers.size() - 1 << '\n';

    return 0;
}
