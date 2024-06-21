#include "Problem_9536.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int CProblem_9536::Solve_Problem()
{
    int iNumTC = { };
    cin >> iNumTC;
    cin.ignore();

    vector<string> vecSays;
    for (int iTC = 0; iTC < iNumTC; ++iTC)
    {
        vecSays.clear();

        string strSays = { };
        getline(cin, strSays);

        string strSrc = { };
        for (auto& iter : strSays)
        {
            if (iter != ' ')
                strSrc.push_back(iter);
            else
            {
                vecSays.push_back(strSrc);
                strSrc = { };
            }
        }
        vecSays.push_back(strSrc);

        while (true)
        {
            string strQues = { };
            getline(cin, strQues);

            bool bCheck = { false }, bFind = { false };
            string strQuesSrc = { };
            for (auto iter = strQues.begin(); iter != strQues.end();)
            {
                if (bCheck == false)
                {
                    if (*iter != ' ')
                        strQuesSrc.push_back(*iter++);
                    else
                    {
                        if (strQuesSrc != "what")
                        {
                            ++iter;
                            ++iter;
                            ++iter;
                            ++iter;
                            ++iter;
                            ++iter;

                            bCheck = true;
                            strQuesSrc = { };
                        }
                        else
                        {
                            bFind = true;
                            break;
                        }
                    }
                }
                else
                {
                    strQuesSrc.push_back(*iter++);
                }
            }

            if (bFind == true)
                break;

            for (auto iter = vecSays.begin(); iter != vecSays.end();)
            {
                if (*iter == strQuesSrc)
                    iter = vecSays.erase(iter);
                else
                    ++iter;
            }
        }

        for (auto& iter : vecSays)
            cout << iter << " ";
        cout << '\n';
    }

    return 0;
}
