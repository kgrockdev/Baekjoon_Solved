#include "Problem_12852.h"

#include <map>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

typedef struct tagElement
{
    int iNum = { };
    vector<int> vecTrajectory;
} ELEM;

int CProblem_12852::Solve_Problem()
{
    int iSrc = { };
    cin >> iSrc;

    list<ELEM> lstBFS;
    map<int, int> mapNumRoute;

    lstBFS.push_back({ iSrc, vector<int>{ } });

    while (lstBFS.size() > 0)
    {
        ELEM tElem = lstBFS.front();
        lstBFS.pop_front();

        if (tElem.iNum == 0)
        {
            cout << tElem.vecTrajectory.size() - 1 << '\n';
            for (auto iter : tElem.vecTrajectory)
                cout << iter << " ";
            cout << '\n';
        
            break;
        }

        tElem.vecTrajectory.push_back(tElem.iNum);
        if (tElem.iNum % 3 == 0)
        {
            auto iter = mapNumRoute.find(tElem.iNum % 3);
            if (iter == mapNumRoute.end() || iter->second > tElem.vecTrajectory.size())
            {
                mapNumRoute.emplace(tElem.iNum / 3, tElem.vecTrajectory.size());
                lstBFS.push_back({ tElem.iNum / 3, tElem.vecTrajectory });
            }
        }
        if (tElem.iNum % 2 == 0)
        {
            auto iter = mapNumRoute.find(tElem.iNum % 2);
            if (iter == mapNumRoute.end() || iter->second > tElem.vecTrajectory.size())
            {
                mapNumRoute.emplace(tElem.iNum / 2, tElem.vecTrajectory.size());
                lstBFS.push_back({ tElem.iNum / 2, tElem.vecTrajectory });
            }
        }
            
        auto iter = mapNumRoute.find(tElem.iNum - 1);
        if (iter == mapNumRoute.end() || iter->second > tElem.vecTrajectory.size())
        {
            mapNumRoute.emplace(tElem.iNum - 1, tElem.vecTrajectory.size());
            lstBFS.push_back({ tElem.iNum - 1, tElem.vecTrajectory });
        }
    }

    return 0;
}
