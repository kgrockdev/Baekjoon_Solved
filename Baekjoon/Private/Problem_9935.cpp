#include "Problem_9935.h"

#include <string>
#include <iostream>

using namespace std;

int CProblem_9935::Solve_Problem()
{
    string strQus = { }, strBomb = { };
    cin >> strQus >> strBomb;

    string strString = { };
    
    for (auto& iter : strQus)
    {
        strString.push_back(iter);
        while (strString.size() >= strBomb.size())
        {
            string strSrc = strString.substr(strString.size() - strBomb.size(), strBomb.size());
            if (strSrc == strBomb)
                strString.erase(strString.size() - strBomb.size(), strBomb.size());
            else
                break;
        }
    }

    if (strString == "")
        strString = "FRULA";

    cout << strString << endl;

    return 0;
}
