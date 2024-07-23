#include "Problem_11286.h"

#include <queue>
#include <iostream>

using namespace std;

struct tagComp11286
{
    bool operator()(int iA, int iB) 
    {
        if (abs(iA) == abs(iB))
            return iA > iB;
        else
            return abs(iA) > abs(iB);
    }
};

int CProblem_11286::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    priority_queue<int, vector<int>, tagComp11286> pqContainer;

    int iNum = { };
    cin >> iNum;

    for (int iIdx = 0; iIdx < iNum; ++iIdx)
    {
        int iSrc = { };
        cin >> iSrc;

        if (iSrc == 0)
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
            pqContainer.emplace(iSrc);
    }

    return 0;
}
