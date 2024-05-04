#include "Problem_1620.h"

using namespace std;

#include <string>
#include <iostream>
#include <unordered_map>

unordered_map<string, string> mapNumKey1620;
unordered_map<string, string> mapNameKey1620;

int CProblem_1620::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNum = { }, iNumQuery = { };
    cin >> iNum >> iNumQuery;

    for (int iIndex = 0; iIndex < iNum; ++iIndex)
    {
        string strName = { };
        cin >> strName;

        mapNumKey1620.emplace(to_string(iIndex + 1), strName);
        mapNameKey1620.emplace(strName, to_string(iIndex + 1));
    }

    for (int iIndex = 0; iIndex < iNumQuery; ++iIndex)
    {
        string strSrc = { };
        cin >> strSrc;

        if (strSrc[0] >= '0' && strSrc[0] <= '9')
            cout << mapNumKey1620.find(strSrc)->second << '\n';
        else
            cout << mapNameKey1620.find(strSrc)->second << '\n';
    }

    return 0;
}
