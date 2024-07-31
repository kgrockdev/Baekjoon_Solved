#include "Problem_1038.h"

#include <string>
#include <iostream>

using namespace std;

int CProblem_1038::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;
    ++iNum; ++iNum;

    if (iNum == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    string strAnswer = { "0" };
    while (iNum > 0)
    {
        bool bCheck = { true };
        for (auto iter = strAnswer.begin(); iter != strAnswer.end(); ++iter)
        {
            if (bCheck == false)
            {
                *iter = '0';
                continue;
            }

            auto nextIter = iter; 
            ++nextIter;

            if (nextIter == strAnswer.end())
                break;

            if (*iter <= *nextIter)
            {
                if (*nextIter < '9')
                    *iter = *nextIter + 1;
                else
                {
                    strAnswer = '0' + strAnswer;
                    iter = strAnswer.begin();
                }

                bCheck = false;
            }
        }

        if (bCheck == true)
        {
            --iNum;
            // cout << strAnswer << '\n';

            if (iNum > 1)
                strAnswer = to_string(stoll(strAnswer) + 1);
        }

        if (strAnswer == "9876543211")
        {
            cout << -1 << '\n';
            return 0;
        }

    }

    cout << strAnswer << '\n';

    return 0;
}