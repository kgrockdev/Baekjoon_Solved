#include "Problem_10815.h"

#include <iostream>
#include <unordered_set>

using namespace std;

int CProblem_10815::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumCard = { }, iQuery = { };
    cin >> iNumCard;

    int iCard = { };
    unordered_set<int> setContainer;
    for (int iCard = 0; iCard < iNumCard; ++iCard)
    {
        cin >> iQuery;
        setContainer.emplace(iQuery);
    }

    cin >> iNumCard;
    for (int iCard = 0; iCard < iNumCard; ++iCard)
    {
        cin >> iQuery;
        if (setContainer.find(iQuery) == setContainer.end()) 
            cout << "0 ";
        else
            cout << "1 ";
    }

    return 0;
}
