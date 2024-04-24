#include "Problem_2596.h"

using namespace std;

#include <string>
#include <iostream>

int CProblem_2596::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    string strSecret = { };
    cin >> strSecret;

    int iError = { -1 };
    string strConvSecret = { };
    for (int iIndex = 0; iIndex < iNum; ++iIndex)
    {
        string strSrc = strSecret.substr(iIndex * 6, 6);

        if (strSrc == "000000")
            strConvSecret += "A";
        else if (strSrc == "001111")
            strConvSecret += "B";
        else if (strSrc == "010011")
            strConvSecret += "C";
        else if (strSrc == "011100")
            strConvSecret += "D";
        else if (strSrc == "100110")
            strConvSecret += "E";
        else if (strSrc == "101001")
            strConvSecret += "F";
        else if (strSrc == "110101")
            strConvSecret += "G";
        else if (strSrc == "111010")
            strConvSecret += "H";
        else
        {

        }
    }

    if (iError == -1)
        cout << strConvSecret << '\n';
    else
        cout << iError << '\n';

    return 0;
}
