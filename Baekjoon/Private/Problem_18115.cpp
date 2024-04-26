#include "Problem_18115.h"

using namespace std;

#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

int CProblem_18115::Solve_Problem()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int iNum = { };
    cin >> iNum;

    vector<int> vecTech;
    for (int iIndex = 0; iIndex < iNum; ++iIndex)
    {
        int iSrc = { };
        cin >> iSrc;

        vecTech.push_back(iSrc);
    }

    list<int> listCard;
    for (int iIndex = 0; iIndex < iNum; ++iIndex)
        listCard.push_back((iNum - iIndex));

    list<int> listInitCard;
    while (vecTech.size() > 0)
    {
        if (vecTech.back() == 1)
        {
            listInitCard.push_back(listCard.back());
            vecTech.pop_back();
            listCard.pop_back();
        }
        else if (vecTech.back() == 2)
        {
            auto iter = listInitCard.begin();

            if (listInitCard.size() != 1)
            {
                iter = listInitCard.end();
                iter--;
            }

            listInitCard.insert(iter, listCard.back());
            vecTech.pop_back();
            listCard.pop_back();
        }
        else if (vecTech.back() == 3)
        {
            listInitCard.push_front(listCard.back());
            vecTech.pop_back();
            listCard.pop_back();
        }
    }

    reverse(listInitCard.begin(), listInitCard.end());
    for (auto& iter : listInitCard)
        cout << iter << " ";

    return 0;
}
