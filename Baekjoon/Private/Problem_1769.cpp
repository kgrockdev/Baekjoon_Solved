#include "Problem_1769.h"

using namespace std;

#include <string>
#include <iostream>

int CProblem_1769::Solve_Problem()
{
    string strQuery = { };
    cin >> strQuery;

    int iStep = { 0 };
    while (strQuery.size() > 1)
    {
        int iTemp = { };
        for (int iIndex = 0; iIndex < strQuery.size(); ++iIndex)
            iTemp += int(strQuery[iIndex] - '0');

        strQuery = to_string(iTemp);
        iStep++;
    }

    cout << iStep << '\n';
    cout << (stoi(strQuery) % 3 == 0 ? "YES" : "NO") << '\n';

    return 0;
}
