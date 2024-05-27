#include "Problem_4999.h"

#include <string>
#include <iostream>

using namespace std;

int CProblem_4999::Solve_Problem()
{
    string strIn = { }, strMy = { };
    cin >> strIn >> strMy;

    if (strIn.length() >= strMy.length())
        cout << "go" << endl;
    else
        cout << "no" << endl;

    return 0;
}
