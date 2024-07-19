#include "Problem_15000.h"

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_15000::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string strSrc = { };
    cin >> strSrc;

    for (auto iter : strSrc)
    {
        cout << (char)(iter - ('a' - 'A'));
    }

    return 0;
}

// earthisunderattack