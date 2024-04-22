#include "Problem_25206.h"

using namespace std;

#include <iostream>

int CProblem_25206::Solve_Problem()
{
    int iNumGrade = { };
    double dScore = { };

    int iNum = { 20 };
    for (int iIndex = 0; iIndex < 20; ++iIndex)
    {
        float fScore = { };
        string strName = { }, strGrade = { };
    
        cin >> strName >> fScore >> strGrade;

        if (strGrade == "P")
            iNum -= 1;
        else
        {
            iNumGrade += fScore;

            if (strGrade == "A+")
            {
                dScore += fScore * 4.5;
            }
            else if (strGrade == "A0")
            {

            }
            else if (strGrade == "B+")
            {

            }
            else if (strGrade == "B0")
            {

            }
            else if (strGrade == "C+")
            {

            }
            else if (strGrade == "C0")
            {

            }
            else if (strGrade == "D+")
            {

            }
            else if (strGrade == "D0")
            {

            }
            else if (strGrade == "F")
            {

            }
        }
    }

    return 0;
}
