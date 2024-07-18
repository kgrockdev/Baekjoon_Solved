#include "Problem_12904.h"

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_12904::Solve_Problem()
{
    bool bFind = { false };

    string strQues = { }, strAns = { };
    cin >> strQues >> strAns;

    while (strQues != strAns)
    {
        if (strQues.size() > strAns.size())
            break;

        char chFunc = strAns.back();

        if (chFunc == 'A')
        {
            strAns.pop_back();
        }
        else
        {
            strAns.pop_back();
            reverse(strAns.begin(), strAns.end());
        }
    }

    if (strQues == strAns)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
