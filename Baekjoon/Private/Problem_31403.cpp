#include "Problem_31403.h"

#include <string>
#include <iostream>

using namespace std;

int CProblem_31403::Solve_Problem()
{
    string strA = { }, strB = { }, strC = { };

    cin >> strA >> strB >> strC;

    cout << stoi(strA) + stoi(strB) - stoi(strC) << endl;
    cout << stoi(strA + strB) - stoi(strC) << endl;

    return 0;
}
