#include "Problem_15651.h"

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_15651::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iN = { }, iM = { };
    cin >> iN >> iM;

    vector<int> vecContainer;
    for (int iIndex = 0; iIndex < iM; ++iIndex)
        vecContainer.push_back(1);
    
    while (true)
    {
        for (auto& iter : vecContainer)
            cout << iter << " ";
        cout << '\n';

        int iDigit = iM - 1;

        vecContainer[iDigit] += 1;

        while (iDigit > 0)
        {
            if (vecContainer[iDigit] > iN)
            {
                vecContainer[iDigit] = 1;

                iDigit -= 1;
                vecContainer[iDigit] += 1;
            }
            else 
                break;
        }

        if (vecContainer[0] > iN)
            break;
    }

    return 0;
}
