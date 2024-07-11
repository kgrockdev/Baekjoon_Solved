#include "Problem_2108.h"

#include <map>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_2108::Solve_Problem()
{
    int iNum = { }, iSum = { };
    cin >> iNum;
    
    vector<int> vecContainer;

    map<int, int> mapPreq;
    vector<pair<int, int>> vecPreq;

    for (int iIndex = 0; iIndex < iNum; ++iIndex)
    {
        int iSrc = { };
        cin >> iSrc;

        iSum += iSrc;
        vecContainer.push_back(iSrc);

        auto iter = mapPreq.find(iSrc);
        if (iter == mapPreq.end())
            mapPreq.emplace(iSrc, 1);
        else
            iter->second = iter->second + 1;
    }

    for (auto& iter : mapPreq)
        vecPreq.push_back({ iter.first, iter.second });
    sort(vecPreq.begin(), vecPreq.end(), 
        [](pair<int, int> pA, pair<int, int> pB) 
        { 
            if (pA.second == pB.second)
                return pA.first < pB.first;
            else
                return pA.second > pB.second; 
        }
    );

    // »ê¼ú Æò±Õ
    float fAvg = (float)iSum / vecContainer.size();
    cout << (int)floor(fAvg + 0.5f) << endl;

    // Áß¾Ó°ª
    sort(vecContainer.begin(), vecContainer.end());
    cout << vecContainer[vecContainer.size() / 2] << endl;

    // ÃÖºó°ª
    if (vecPreq[0].second == vecPreq[1].second)
        cout << vecPreq[1].first << endl;
    else
        cout << vecPreq[0].first << endl;

    // ¹üÀ§
    cout << abs(vecContainer.back() - vecContainer.front()) << endl;

    return 0;
}
