#include "Problem_1436.h"

#include <string>
#include <iostream>

using namespace std;

int CProblem_1436::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    string strAnswer = { "666" };

    while (iNum > 1)
    {
        strAnswer = to_string(stoi(strAnswer) + 1);

        size_t siOff = strAnswer.find("666");
        if (siOff != -1)
            --iNum;
    }

    cout << strAnswer << '\n';

    return 0;
}