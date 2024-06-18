#include "Problem_16677.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int CProblem_16677::Solve_Problem()
{
    string strWord = { };
    cin >> strWord;

    int iNum = { };
    cin >> iNum;

    vector<pair<string, int>> vecDictionary;

    for (int iIndex = 0; iIndex < iNum; ++iIndex)
    {
        string strSrc = { };
        int iWeight = { };

        cin >> strSrc >> iWeight;
        vecDictionary.push_back({ strSrc, iWeight });
    }

    float fWeightAnswer = { 0.f };
    string strAnswer = { "No Jam" };
    for (auto& iter : vecDictionary)
    {
        int iWeight = { 0 };
        int iDigit = { 0 };

        for (auto& chIter : iter.first)
        {
            if (iDigit < strWord.size() &&
                strWord[iDigit] == chIter)
                ++iDigit;
            else
                ++iWeight;
        }

        if (iDigit == strWord.size() &&
            fWeightAnswer < (float)iter.second / (float)iWeight)
        {
            fWeightAnswer = (float)iter.second / (float)iWeight;
            strAnswer = iter.first;
        }
    }

    cout << strAnswer << endl;

    return 0;
}
