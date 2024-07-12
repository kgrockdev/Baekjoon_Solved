#include "Problem_2023.h"

#include <cmath>
#include <list>
#include <iostream>

using namespace std;

bool Check_2023(int iCheck)
{
    int iSqrt = sqrt(iCheck);
    for (int iIndex = 2; iIndex <= iSqrt; ++iIndex)
    {
        if (iCheck % iIndex == 0)
            return false;
    }

    return true;
}

int CProblem_2023::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNum = { }, iPow = { };
    cin >> iNum;
    iPow = pow(10, iNum - 1);

    list<int> lstContainer;
    lstContainer.push_back(2);
    lstContainer.push_back(3);
    lstContainer.push_back(5);
    lstContainer.push_back(7);

    while (lstContainer.front() < iPow)
    {
        list<int> lstSrcContainer;

        for (auto iter = lstContainer.begin(); iter != lstContainer.end();)
        {
            int iSrc = *iter;
            iter = lstContainer.erase(iter);

            for (int iDigit = 0; iDigit < 10; ++iDigit)
            {
                int iCheck = iSrc * 10 + iDigit;

                if (Check_2023(iCheck) == true)
                    lstSrcContainer.push_back(iCheck);
            }
        }

        lstContainer.swap(lstSrcContainer);
    }

    for (auto iter : lstContainer)
        cout << iter << '\n';

    return 0;
}