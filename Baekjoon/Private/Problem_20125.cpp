#include "Problem_20125.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int CProblem_20125::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    pair<int, int> pairHeart = { };
    vector<vector<string>> vecContainer;

    for (int iRow = 0; iRow < iNum; ++iRow)
    {
        bool bCheck = { false };

        vector<string> vecSrc;
        for (int iCol = 0; iCol < iNum; ++iCol)
        {
            char chSrc = { };
            cin >> chSrc;

            string strSrc = { };
            strSrc.push_back(chSrc);

            vecSrc.push_back(strSrc);

            if (strSrc == "*")
            {
                if (bCheck == true && vecContainer[iRow - 1][iCol] == "*")
                {
                    pairHeart.first = iRow;
                    pairHeart.second = iCol;
                }
                else
                    bCheck = true;
            }
            else
                bCheck = false;
        }
        vecContainer.push_back(vecSrc);
    }

    cout << pairHeart.first + 1 << " " << pairHeart.second + 1 << '\n';

    int iAnswer = { };
    pair<int, int> pairSrc = { };
    
    // ¿ÞÂÊ ÆÈ
    iAnswer = 0;
    pairSrc = pairHeart;
    while (true)
    {
        --pairSrc.second;
        if (pairSrc.second < 0)
            break;

        if (vecContainer[pairSrc.first][pairSrc.second] == "*")
            ++iAnswer;
        else
            break;
    }

    cout << iAnswer << " ";

    // ¿À¸¥ÂÊ ÆÈ
    iAnswer = 0;
    pairSrc = pairHeart;
    while (true)
    {
        ++pairSrc.second;
        if (pairSrc.second > vecContainer[0].size() - 1)
            break;

        if (vecContainer[pairSrc.first][pairSrc.second] == "*")
            ++iAnswer;
        else
            break;
    }

    cout << iAnswer << " ";

    // Çã¸®
    iAnswer = 0;
    pairSrc = pairHeart;
    while (true)
    {
        ++pairSrc.first;
        if (pairSrc.first > vecContainer.size() - 1)
            break;

        if (vecContainer[pairSrc.first][pairSrc.second] == "*")
            ++iAnswer;
        else
            break;
    }

    cout << iAnswer << " ";

    pair<int, int> pairLeg = pairSrc;

    // ¿ÞÂÊ ´Ù¸®
    iAnswer = 0;
    pairSrc = pairLeg;
    pairSrc.second -= 1;
    while (true)
    {
        if (pairSrc.first > vecContainer.size() - 1)
            break;

        if (vecContainer[pairSrc.first][pairSrc.second] == "*")
            ++iAnswer;
        else
            break;

        ++pairSrc.first;
    }

    cout << iAnswer << " ";

    // ¿À¸¥ÂÊ ´Ù¸®
    iAnswer = 0;
    pairSrc = pairLeg;
    pairSrc.second += 1;
    while (true)
    {
        if (pairSrc.first > vecContainer.size() - 1)
            break;

        if (vecContainer[pairSrc.first][pairSrc.second] == "*")
            ++iAnswer;
        else
            break;

        ++pairSrc.first;
    }

    cout << iAnswer << " ";

    return 0;
}


// ¿ÞÂÊ ÆÈ, ¿À¸¥ÂÊ ÆÈ, Çã¸®, ¿ÞÂÊ ´Ù¸®, ¿À¸¥ÂÊ ´Ù¸®