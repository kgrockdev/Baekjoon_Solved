#include "Problem_10026.h"

#include <list>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_10026::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iAnsNone = { 0 }, iAnsRG = { 0 };

    int iNumRowCol = { };
    cin >> iNumRowCol;

    vector<string> vecMaze;
    vector<string> vecRGMaze;
    vector<string> vecVisited;
    vecMaze.reserve(iNumRowCol + 1);

    for (int iRow = 0; iRow < iNumRowCol; ++iRow)
    {
        string strSrc = { };
        cin >> strSrc;

        vecMaze.push_back(strSrc);
        vecVisited.push_back(strSrc);

        for_each(strSrc.begin(), strSrc.end(), [](char& chSrc) { chSrc = (chSrc == 'G') ? 'R' : chSrc; });
        vecRGMaze.push_back(strSrc);
    }

    // AnsNone
    {
        vector<string> vecSrcVisited = vecVisited;

        list<pair<int, int>> lstColorBFS;
        list<pair<int, int>> lstSearchBFS;
        lstColorBFS.push_back({ 0, 0 });

        while (lstColorBFS.size() > 0)
        {
            pair<int, int> pairSrc = lstColorBFS.front();
            lstColorBFS.pop_front();

            if (vecSrcVisited[pairSrc.first][pairSrc.second] == '0')
                continue;

            lstSearchBFS.push_back(pairSrc);
            vecSrcVisited[pairSrc.first][pairSrc.second] = '0';
            ++iAnsNone;

            while (lstSearchBFS.size() > 0)
            {
                pair<int, int> pairSearch = lstSearchBFS.front();
                lstSearchBFS.pop_front();

                // L
                if (pairSearch.second > 0 &&
                    vecSrcVisited[pairSearch.first][pairSearch.second - 1] != '0')
                {
                    if (vecMaze[pairSearch.first][pairSearch.second] == vecMaze[pairSearch.first][pairSearch.second - 1]) // Same Color
                    {
                        vecSrcVisited[pairSearch.first][pairSearch.second - 1] = '0';
                        lstSearchBFS.push_back({ pairSearch.first, pairSearch.second - 1 });
                    }
                    else
                    {
                        lstColorBFS.push_back({ pairSearch.first, pairSearch.second - 1 });
                    }
                }

                // R
                if (pairSearch.second < iNumRowCol - 1 &&
                    vecSrcVisited[pairSearch.first][pairSearch.second + 1] != '0')
                {
                    if (vecMaze[pairSearch.first][pairSearch.second] == vecMaze[pairSearch.first][pairSearch.second + 1]) // Same Color
                    {
                        vecSrcVisited[pairSearch.first][pairSearch.second + 1] = '0';
                        lstSearchBFS.push_back({ pairSearch.first, pairSearch.second + 1 });
                    }
                    else
                    {
                        lstColorBFS.push_back({ pairSearch.first, pairSearch.second + 1 });
                    }
                }

                // T
                if (pairSearch.first > 0 &&
                    vecSrcVisited[pairSearch.first - 1][pairSearch.second] != '0')
                {
                    if (vecMaze[pairSearch.first][pairSearch.second] == vecMaze[pairSearch.first - 1][pairSearch.second]) // Same Color
                    {
                        vecSrcVisited[pairSearch.first - 1][pairSearch.second] = '0';
                        lstSearchBFS.push_back({ pairSearch.first - 1, pairSearch.second });
                    }
                    else
                    {
                        lstColorBFS.push_back({ pairSearch.first - 1, pairSearch.second });
                    }
                }

                // B
                if (pairSearch.first < iNumRowCol - 1 &&
                    vecSrcVisited[pairSearch.first + 1][pairSearch.second] != '0')
                {
                    if (vecMaze[pairSearch.first][pairSearch.second] == vecMaze[pairSearch.first + 1][pairSearch.second]) // Same Color
                    {
                        vecSrcVisited[pairSearch.first + 1][pairSearch.second] = '0';
                        lstSearchBFS.push_back({ pairSearch.first + 1, pairSearch.second });
                    }
                    else
                    {
                        lstColorBFS.push_back({ pairSearch.first + 1, pairSearch.second });
                    }
                }
            }
        }
    }

    // AnsRG
    {
        vector<string> vecSrcVisited = vecVisited;

        list<pair<int, int>> lstColorBFS;
        list<pair<int, int>> lstSearchBFS;
        lstColorBFS.push_back({ 0, 0 });

        while (lstColorBFS.size() > 0)
        {
            pair<int, int> pairSrc = lstColorBFS.front();
            lstColorBFS.pop_front();

            if (vecSrcVisited[pairSrc.first][pairSrc.second] == '0')
                continue;

            lstSearchBFS.push_back(pairSrc);
            vecSrcVisited[pairSrc.first][pairSrc.second] = '0';
            ++iAnsRG;

            while (lstSearchBFS.size() > 0)
            {
                pair<int, int> pairSearch = lstSearchBFS.front();
                lstSearchBFS.pop_front();

                // L
                if (pairSearch.second > 0 &&
                    vecSrcVisited[pairSearch.first][pairSearch.second - 1] != '0')
                {
                    if (vecRGMaze[pairSearch.first][pairSearch.second] == vecRGMaze[pairSearch.first][pairSearch.second - 1]) // Same Color
                    {
                        vecSrcVisited[pairSearch.first][pairSearch.second - 1] = '0';
                        lstSearchBFS.push_back({ pairSearch.first, pairSearch.second - 1 });
                    }
                    else
                    {
                        lstColorBFS.push_back({ pairSearch.first, pairSearch.second - 1 });
                    }
                }

                // R
                if (pairSearch.second < iNumRowCol - 1 &&
                    vecSrcVisited[pairSearch.first][pairSearch.second + 1] != '0')
                {
                    if (vecRGMaze[pairSearch.first][pairSearch.second] == vecRGMaze[pairSearch.first][pairSearch.second + 1]) // Same Color
                    {
                        vecSrcVisited[pairSearch.first][pairSearch.second + 1] = '0';
                        lstSearchBFS.push_back({ pairSearch.first, pairSearch.second + 1 });
                    }
                    else
                    {
                        lstColorBFS.push_back({ pairSearch.first, pairSearch.second + 1 });
                    }
                }

                // T
                if (pairSearch.first > 0 &&
                    vecSrcVisited[pairSearch.first - 1][pairSearch.second] != '0')
                {
                    if (vecRGMaze[pairSearch.first][pairSearch.second] == vecRGMaze[pairSearch.first - 1][pairSearch.second]) // Same Color
                    {
                        vecSrcVisited[pairSearch.first - 1][pairSearch.second] = '0';
                        lstSearchBFS.push_back({ pairSearch.first - 1, pairSearch.second });
                    }
                    else
                    {
                        lstColorBFS.push_back({ pairSearch.first - 1, pairSearch.second });
                    }
                }

                // B
                if (pairSearch.first < iNumRowCol - 1 &&
                    vecSrcVisited[pairSearch.first + 1][pairSearch.second] != '0')
                {
                    if (vecRGMaze[pairSearch.first][pairSearch.second] == vecRGMaze[pairSearch.first + 1][pairSearch.second]) // Same Color
                    {
                        vecSrcVisited[pairSearch.first + 1][pairSearch.second] = '0';
                        lstSearchBFS.push_back({ pairSearch.first + 1, pairSearch.second });
                    }
                    else
                    {
                        lstColorBFS.push_back({ pairSearch.first + 1, pairSearch.second });
                    }
                }
            }
        }
    }

    cout << iAnsNone << " " << iAnsRG << '\n';

    return 0;
}