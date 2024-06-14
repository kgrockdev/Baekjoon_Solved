#include "Problem_27951.h"

#include <map>
#include <iostream>

using namespace std;

int CProblem_27951::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    map<int, int> mapPrevClassification;
    map<int, int> mapCompClassification;

    for (int iIndex = 0; iIndex < iNum; ++iIndex)
    {
        int iSrc = { };
        cin >> iSrc;

        mapPrevClassification.emplace(iIndex, iSrc);
    }

    int iTop = { }, iBottom = { };
    cin >> iTop >> iBottom;

    // 1, 2에 대한 처리
    for (auto iter = mapPrevClassification.begin(); iter != mapPrevClassification.end();)
    {
        switch (iter->second)
        {
        case 1:
            --iTop;
            mapCompClassification.emplace(iter->first, iter->second);
            iter = mapPrevClassification.erase(iter);
            break;

        case 2:
            --iBottom;
            mapCompClassification.emplace(iter->first, iter->second);
            iter = mapPrevClassification.erase(iter);
            break;

        case 3:
            ++iter;
        }
    }

    // 3에 대한 처리
    for (auto iter = mapPrevClassification.begin(); iter != mapPrevClassification.end();)
    {
        if (iTop > 0)
        {
            --iTop;
            mapCompClassification.emplace(iter->first, 1);
            iter = mapPrevClassification.erase(iter);
        }
        else if (iBottom > 0)
        {
            --iBottom;
            mapCompClassification.emplace(iter->first, 2);
            iter = mapPrevClassification.erase(iter);
        }
    }

    if (iTop > 0 || iBottom > 0)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << '\n';
        for (auto iter : mapCompClassification)
            cout << ((iter.second == 1) ? "U" : "D");
        cout << '\n';
    }

    return 0;
}
