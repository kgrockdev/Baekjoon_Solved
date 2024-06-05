#include "Problem_1339.h"

#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int CProblem_1339::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNumWord = { };
    cin >> iNumWord;

    string strSrc = { };
    vector<string> vecWords;
    unordered_map<char, unsigned long long> mapExponent;
    for (int iWord = 0; iWord < iNumWord; ++iWord)
    {
        cin >> strSrc;
        vecWords.push_back(strSrc);
        for (auto iter = strSrc.begin(); iter != strSrc.end(); ++iter)
        {
            auto exIter = mapExponent.find(*iter);
            if (exIter != mapExponent.end())
                exIter->second += pow(10, strSrc.length() - distance(strSrc.begin(), iter) - 1);
            else
                mapExponent.emplace(*iter, pow(10, strSrc.length() - distance(strSrc.begin(), iter) - 1));
        }
    }

    int iNum = { 9 };
    unordered_map<char, int> mapConv;
    while (mapExponent.size() > 0)
    {
        unsigned long long ullMax = { 0 };
        char chKey = { };
        for (auto iter = mapExponent.begin(); iter != mapExponent.end(); ++iter)
        {
            if (ullMax < iter->second)
            {
                chKey = iter->first;
                ullMax = iter->second;
            }
        }

        mapConv.emplace(chKey, iNum--);
        mapExponent.erase(chKey);
    }

    int iRes = { };
    for (auto& wordIter : vecWords)
    {
        for (auto& charIter : wordIter)
        {
            charIter = mapConv.find(charIter)->second + '0';
        }

        iRes += stoi(wordIter);
    }

    cout << iRes << endl;

    return 0;
}
