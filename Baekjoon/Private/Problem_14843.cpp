#include "Problem_14843.h"

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_14843::Solve_Problem()
{
    int iNumSolve = { };
    cin >> iNumSolve;

    double dScore = { };
    for (int iSolve = 0; iSolve < iNumSolve; ++iSolve)
    {
        double dS = { };
        int iA = { }, iT = { }, iM = { };

        cin >> dS >> iA >> iT >> iM;

        dScore += (dS * (1.f + 1.f / iA) * (1.f + (double)iM / (double)iT)) / 4;
    }

    int iNumPeople = { };
    cin >> iNumPeople;

    vector<double> vecContainer;
    for (int iPeople = 0; iPeople < iNumPeople; ++iPeople)
    {
        double dS = { };
        cin >> dS;
        vecContainer.push_back(dS);
    }
    sort(vecContainer.begin(), vecContainer.end(), greater<>());

    int iGod = floor((vecContainer.size() + 1) * 0.15f);

    cout << fixed;
    cout.precision(2);

    if (vecContainer[iGod - 1] > dScore)
        cout << "The total score of Younghoon is " << dScore << "." << endl;
    else
        cout << "The total score of Younghoon \"The God\" is " << dScore << "." << endl;

    return 0;
}
