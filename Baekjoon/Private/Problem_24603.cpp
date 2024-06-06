#include "Problem_24603.h"

#include <iostream>

using namespace std;

int CProblem_24603::Solve_Problem()
{
    unsigned long long iNumA = { }, iB = { }, iC = { };
    cin >> iNumA >> iB >> iC;
    
    for (int iA = 0; iA < iNumA; ++iA)
    {
        unsigned long long iSrc = { };
        cin >> iSrc;

        cout << iSrc * iC / iB << endl;
    }

    return 0;
}
