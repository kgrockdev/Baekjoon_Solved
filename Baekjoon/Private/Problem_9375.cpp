#include "Problem_9375.h"

#include <map>
#include <string>
#include <iostream>

using namespace std;

int CProblem_9375::Solve_Problem()
{
    int iNumTC = { };
    cin >> iNumTC;

    int iNumWear = { };
    for (int iTC = 0; iTC < iNumTC; ++iTC)
    {
        map<string, int> mapContainer;

        cin >> iNumWear;

        for (int iWear = 0; iWear < iNumWear; ++iWear)
        {
            string strWear = { };
            cin >> strWear >> strWear;

            auto iter = mapContainer.find(strWear);
            if (iter != mapContainer.end())
                iter->second = iter->second + 1;
            else
                mapContainer.emplace(strWear, 1);
        }

        int iNumAns = { 1 };
        for (auto& iter : mapContainer)
            iNumAns *= (iter.second + 1);
        
        cout << iNumAns - 1 << '\n';
    }

    return 0;
}
