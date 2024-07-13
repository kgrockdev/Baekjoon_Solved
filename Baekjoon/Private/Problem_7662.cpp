#include "Problem_7662.h"

#include <set>
#include <iostream>

using namespace std;

int CProblem_7662::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumTC = { };
    cin >> iNumTC;

    for (int iTC = 0; iTC < iNumTC; ++iTC)
    {
        multiset<int> setContainer;

        int iNumData = { };
        cin >> iNumData;

        for (int iData = 0; iData < iNumData; ++iData)
        {
            char chSrc = { };
            int iSrc = { };
            cin >> chSrc >> iSrc;

            if (chSrc == 'I')
                setContainer.emplace(iSrc);
            else
            {
                if (setContainer.size() > 0)
                {
                    if (iSrc == -1)
                        setContainer.erase(setContainer.begin());
                    else
                        setContainer.erase(--setContainer.end());
                }
            }
        }

        if (setContainer.size() > 0)
            cout << *setContainer.rbegin() << " " << *setContainer.begin() << '\n';
        else
            cout << "EMPTY" << '\n';
    }

    return 0;
}
