#include "Problem_2529.h"

#include <vector>
#include <iostream>

using namespace std;

#define LEFT true
#define RIGHT false

int CProblem_2529::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    vector<char> vecOriginInSign;
    vector<int> vecHighAnswer;
    vector<int> vecLowAnswer;
    for (int iIndex = 0; iIndex < iNum; ++iIndex)
    {
        char chSrc = { };
        cin >> chSrc;

        vecOriginInSign.push_back(chSrc);
        vecHighAnswer.push_back(-1);
        vecLowAnswer.push_back(-1);
    }
    vecHighAnswer.push_back(-1);
    vecLowAnswer.push_back(-1);

    int iDigit = { };
    int iNext = { 9 };
    bool bMode = { RIGHT };
    vector<char> vecInSign = vecOriginInSign;

    // High
    while (true)
    {
        if (bMode == RIGHT)
        {
            bool bFind = { false };
            for (auto iter = vecInSign.begin(); iter != vecInSign.end(); ++iter)
            {
                if (*iter == '>')
                {
                    bFind = true;

                    *iter = '|';
                    iDigit = distance(vecInSign.begin(), iter) - 1;
                    vecHighAnswer[distance(vecInSign.begin(), iter)] = iNext--;
                    break;
                }
            }

            if (bFind == false)
            {
                for (int iIndex = vecInSign.size(); iIndex >= 0; --iIndex)
                {
                    if (vecHighAnswer[iIndex] != -1)
                        break;

                    vecHighAnswer[iIndex] = iNext--;
                }

                break;
            }

            bMode = LEFT;
        }
        else
        {
            for (int iIndex = iDigit; iIndex >= 0; --iIndex)
            {
                if (vecHighAnswer[iIndex] != -1)
                    break;

                vecInSign[iIndex] = '|';
                vecHighAnswer[iIndex] = iNext--;
            }

            bMode = RIGHT;
        }
    }

    iDigit = { };
    iNext = { 0 };
    bMode = { LEFT };
    vecInSign = vecOriginInSign;

    // Low
    while (true)
    {
        if (bMode == LEFT)
        {
            bool bFind = { false };
            for (auto iter = vecInSign.begin(); iter != vecInSign.end(); ++iter)
            {
                if (*iter == '<')
                {
                    bFind = true;

                    *iter = '|';
                    iDigit = distance(vecInSign.begin(), iter) - 1;
                    vecLowAnswer[distance(vecInSign.begin(), iter)] = iNext++;
                    break;
                }
            }

            if (bFind == false)
            {
                for (int iIndex = vecInSign.size(); iIndex >= 0; --iIndex)
                {
                    if (vecLowAnswer[iIndex] != -1)
                        break;

                    vecLowAnswer[iIndex] = iNext++;
                }

                break;
            }

            bMode = RIGHT;
        }
        else
        {
            for (int iIndex = iDigit; iIndex >= 0; --iIndex)
            {
                if (vecLowAnswer[iIndex] != -1)
                    break;

                vecInSign[iIndex] = '|';
                vecLowAnswer[iIndex] = iNext++;
            }

            bMode = LEFT;
        }
    }

    for (auto iter : vecHighAnswer)
        cout << iter;
    cout << '\n';

    for (auto iter : vecLowAnswer)
        cout << iter;
    cout << '\n';

    return 0;
}
