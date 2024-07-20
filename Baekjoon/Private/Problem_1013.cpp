#include "Problem_1013.h"

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define NONE -1
#define MODE_A 1
#define MODE_AA 2
#define MODE_B 10

int CProblem_1013::Solve_Problem()
{
    int iNumCode = { };
    cin >> iNumCode;

    for (int iCode = 0; iCode < iNumCode; ++iCode)
    {
        string strSrc = { };
        cin >> strSrc;

        reverse(strSrc.begin(), strSrc.end());

        int iMode = { NONE };
        string strCheck = { };
        while (strSrc.size() > 0)
        {

            if (iMode == NONE)
            {
                strCheck = strSrc.back();
                strSrc.pop_back();

                if (strCheck == "1")
                    iMode = MODE_A;
                else
                    iMode = MODE_B;
            }
            else
            {
                if (iMode == MODE_B)
                {
                    if (strSrc.back() != '1')
                        break;
                    else
                    {
                        strCheck.push_back(strSrc.back());
                        strSrc.pop_back();

                        iMode = NONE;
                    }
                }
                else if (iMode == MODE_A)
                {
                    if (strSrc.back() != '0')
                        break;
                    else
                    {
                        strCheck.push_back(strSrc.back());
                        strSrc.pop_back();

                        if (strCheck == "100")
                        {
                            strCheck.clear();
                            iMode = MODE_AA;
                        }
                    }
                }
                else if (iMode == MODE_AA)
                {
                    if (strSrc.back() == '0')
                    {
                        strCheck.push_back(strSrc.back());
                        strSrc.pop_back();

                        iMode = MODE_B;
                    }
                    else
                    {
                        strCheck.push_back(strSrc.back());
                        strSrc.pop_back();

                        if (strCheck == "1" && strSrc.size() == 0)
                            break;

                        if (strSrc.back() == '1')
                            strCheck.clear();
                        else
                        {
                            strCheck.clear();
                            strSrc.pop_back();

                            if (strSrc.back() == '1')
                            {
                                iMode = NONE;
                            }
                        }
                    }
                }
            }
        }

        if (strSrc.size() == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
