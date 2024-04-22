#include "Problem_2776.h"

using namespace std;

#include <vector>
#include <iostream>
#include <unordered_set>

int CProblem_2776::Solve_Problem()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int iNumCase = { };
    cin >> iNumCase;

    for (int iCase = 0; iCase < iNumCase; ++iCase)
    {
        vector<short> vecRes;
        unordered_set<int> setNote;

        int iNote_1 = { }, iNote_2 = { };

        cin >> iNote_1;
        for (int iIndex = 0; iIndex < iNote_1; ++iIndex)
        {
            int iNumber = { };
            cin >> iNumber;

            setNote.emplace(iNumber);
        }

        cin >> iNote_2;
        for (int iIndex = 0; iIndex < iNote_2; ++iIndex)
        {
            int iNumber = { };
            cin >> iNumber;

            if (setNote.find(iNumber) != setNote.end())
                vecRes.push_back(1);
            else
                vecRes.push_back(0);
        }

        for (int iIndex = 0; iIndex < vecRes.size(); ++iIndex)
            cout << vecRes[iIndex] << '\n';
    }

    return 0;
}
