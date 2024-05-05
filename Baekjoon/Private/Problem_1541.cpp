#include "Problem_1541.h"

using namespace std;

#include <list>
#include <string>
#include <iostream>

int CProblem_1541::Solve_Problem()
{
    string strSrc = { };
    cin >> strSrc;

    list<string> listContainer;

    int iLastDigit = { 0 };
    for (int iIndex = 0; iIndex < strSrc.length(); ++iIndex)
    {
        if (strSrc[iIndex] == '-' || strSrc[iIndex] == '+')
        {
            listContainer.push_back(strSrc.substr(iLastDigit, iIndex - iLastDigit));    // 정수
            listContainer.push_back(strSrc.substr(iIndex, 1));             // 기호

            iLastDigit = iIndex + 1;
        }
    }
    listContainer.push_back(strSrc.substr(iLastDigit, strSrc.length() - iLastDigit));
    
    while (true)
    {
        bool bBreak = { true };

        auto iterBegin = listContainer.begin();
        for (auto iter = listContainer.begin(); iter != listContainer.end(); ++iter)
        {
            if (*iter == "-")
                iterBegin = iter;
            else if (*iter == "+" && iterBegin != listContainer.begin())
            {
                int iSrc = { stoi(*++iterBegin) };

                iterBegin = listContainer.erase(iterBegin);
                iterBegin = listContainer.erase(iterBegin);

                iSrc += stoi(*iterBegin);

                iterBegin = listContainer.erase(iterBegin);
                listContainer.insert(iterBegin, to_string(iSrc));

                bBreak = false;
                break;
            }
        }

        if (bBreak == true) break;
    }

    while (listContainer.size() > 1)
    {
        auto iter = listContainer.begin();

        int iSrc = stoi(*iter++);
        iSrc = (*iter++ == "+") ? (iSrc + stoi(*iter)) : (iSrc - stoi(*iter));

        listContainer.pop_front();
        listContainer.pop_front();
        listContainer.pop_front();

        listContainer.push_front(to_string(iSrc));
    }

    cout << listContainer.front() << '\n';

    return 0;
}
