#include "Problem_1764.h"

using namespace std;

#include <set>
#include <string>
#include <iostream>

int CProblem_1764::Solve_Problem()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int iNumHear = { }, iNumLook = { };
    cin >> iNumHear >> iNumLook;

    set<string> setName;
    set<string> setResName;

    for (int iIndex = 0; iIndex < iNumHear; ++iIndex)
    {
        string strName = { };
        cin >> strName;

        setName.emplace(strName);
    }

    int iLength = { };
    for (int iIndex = 0; iIndex < iNumLook; ++iIndex)
    {
        string strName = { };
        cin >> strName;

        if (setName.find(strName) != setName.end())
        {
            iLength++;
            setResName.emplace(strName);
        }
    }

    cout << iLength << '\n';
    for (auto& iter : setResName)
        cout << iter << '\n';


    return 0;
}
