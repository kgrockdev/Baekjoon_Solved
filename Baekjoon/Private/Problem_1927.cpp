#include "Problem_1927.h"

#include <queue>
#include <iostream>

using namespace std;

int CProblem_1927::Solve_Problem()
{
    // 11279번 문제 동일 (grater > less)

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumCalc = { };
    cin >> iNumCalc;

    priority_queue<int, vector<int>, greater<int>> pqContainer;

    for (int iCalc = 0; iCalc < iNumCalc; ++iCalc)
    {
        int iNum = { };
        cin >> iNum;

        if (iNum == 0)
        {
            if (pqContainer.size() > 0)
            {
                cout << pqContainer.top() << '\n';
                pqContainer.pop();
            }
            else
                cout << 0 << '\n';
        }
        else
            pqContainer.emplace(iNum);
    }

    return 0;
}
