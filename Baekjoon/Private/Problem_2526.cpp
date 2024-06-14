#include "Problem_2526.h"

#include <iostream>
#include <unordered_map>

using namespace std;

int CProblem_2526::Solve_Problem()
{
    int iStartNum = { }, iDivideNum = { };
    cin >> iStartNum >> iDivideNum;

    unordered_map<int, int> mapContainer;

    int iPrev = { iStartNum };
    while (true)
    {
        iPrev = (iPrev * iStartNum) % iDivideNum;

        auto iter = mapContainer.find(iPrev);

        if (iter == mapContainer.end())
            mapContainer.emplace(iPrev, mapContainer.size());
        else
        {
            cout << mapContainer.size() - iter->second << endl;
            return 0;
        }
    }

    return 0;
}
