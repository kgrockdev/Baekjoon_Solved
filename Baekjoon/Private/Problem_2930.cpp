#include "Problem_2930.h"

using namespace std;

#include <vector>
#include <iostream>

int Calc_Score(char chSelf, char chOther)
{
    if (chSelf == chOther)
        return 1;
    else
    {
        if (chSelf == 'S')
        {
            if (chOther == 'P') return 2;
            else return 0;
        }

        else if (chSelf == 'P')
        {
            if (chOther == 'R') return 2;
            else return 0;
        }

        else if (chSelf == 'R')
        {
            if (chOther == 'S') return 2;
            else return 0;
        }
    }

    return 0;
}

int CProblem_2930::Solve_Problem()
{
    int iRound = { }, iFriend = { };
    int iScore = { }, iMaxScore = { };

    cin >> iRound;

    vector<char> vecRCPSelf;

    for (int iIndex = 0; iIndex < iRound; ++iIndex)
    {
        char chInput = { };
        cin >> chInput;

        vecRCPSelf.push_back(chInput);
    }

    cin >> iFriend;

    vector<vector<char>> vecRCPFriend;

    for (int iFrdIdx = 0; iFrdIdx < iFriend; ++iFrdIdx)
    {
        vector<char> vecFriend;

        for (int iRdIdx = 0; iRdIdx < iRound; ++iRdIdx)
        {
            char chInput = { };
            cin >> chInput;

            iScore += Calc_Score(vecRCPSelf[iRdIdx], chInput);

            vecFriend.push_back(chInput);
        }

        vecRCPFriend.push_back(vecFriend);
    }

    for (int iIndex = 0; iIndex < iRound; ++iIndex)
    {
        int iTempScore = { }, iAccScore = { };

        for (int iFrdIdx = 0; iFrdIdx < iFriend; ++iFrdIdx)
            iTempScore += Calc_Score('S', vecRCPFriend[iFrdIdx][iIndex]);
        iAccScore = max(iAccScore, iTempScore); iTempScore = 0;

        for (int iFrdIdx = 0; iFrdIdx < iFriend; ++iFrdIdx)
            iTempScore += Calc_Score('P', vecRCPFriend[iFrdIdx][iIndex]);
        iAccScore = max(iAccScore, iTempScore); iTempScore = 0;

        for (int iFrdIdx = 0; iFrdIdx < iFriend; ++iFrdIdx)
            iTempScore += Calc_Score('R', vecRCPFriend[iFrdIdx][iIndex]);
        iAccScore = max(iAccScore, iTempScore); iTempScore = 0;

        iMaxScore += iAccScore;
    }

    cout << iScore << '\n' << iMaxScore << '\n';

    return 0;
}
