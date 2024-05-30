#include "Problem_1011.h"

#include <list>
#include <iostream>
#include <unordered_map>

using namespace std;

int CProblem_1011::Solve_Problem()
{
    int iX = { }, iY = { }, iD = { };
    int iNumTC = { };
    cin >> iNumTC;

    for (int iTC = 0; iTC < iNumTC; ++iTC)
    {
        cin >> iX >> iY;

        iD = iY - iX;


    }

    return 0;
}

// 1 1 1    : 3
// 1 2 1    : 4
// 1 2 1 1  : 5
// 1 2 2 1  : 6