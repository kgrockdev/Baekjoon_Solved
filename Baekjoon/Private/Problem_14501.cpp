#include "Problem_14501.h"

using namespace std;

#include <map>
#include <iostream>

typedef struct tagConsulting
{
    int iDay = { };
    int iPay = { };
} CONS;

int CProblem_14501::Solve_Problem()
{
    map<int, CONS> mapCont14501;
    int arrCont14501[16] = { };

    fill_n(arrCont14501, 16, 0);

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumDay = { };
    cin >> iNumDay;

    for (int iIndex = 0; iIndex < iNumDay; ++iIndex)
    {
        CONS tSrc = { };
        cin >> tSrc.iDay >> tSrc.iPay;

        mapCont14501.emplace(iIndex, tSrc);
    }

    for (int iIndex = 0; iIndex < iNumDay; ++iIndex)
    {
        int iCurrDay = iNumDay - iIndex - 1;
        auto iter = mapCont14501.find(iCurrDay);

        int iCompDay = iCurrDay + iter->second.iDay;
        if (iCompDay > iNumDay)
            arrCont14501[iCurrDay] = arrCont14501[iCurrDay + 1];
        else
            arrCont14501[iCurrDay] = max(arrCont14501[iCurrDay + 1], iter->second.iPay + arrCont14501[iCompDay]);
    }

    cout << arrCont14501[0] << '\n';

    return 0;
}
