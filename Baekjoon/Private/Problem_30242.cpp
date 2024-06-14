#include "Problem_30242.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool         bFlag;
int          iNumRowCol;
vector<int>  vecBoard;
vector<bool> vecFixed;

unordered_set<int> setBanned;

bool Recursive_30242(int iRow)
{
    if (iRow > iNumRowCol - 2)
    {
        if (bFlag == true)
            reverse(vecBoard.begin(), vecBoard.end());

        for (auto iter : vecBoard)
            cout << iter + 1 << " ";

        return true;
    }

    if (vecFixed[iRow + 1] == true)
    {
        bool bCheck = { false };
        for (int iNavRow = 0; iNavRow < iRow + 1; ++iNavRow)
        {
            if (vecBoard[iNavRow] == vecBoard[iRow + 1])
            {
                bCheck = true;
                break;
            }

            if (abs(vecBoard[iNavRow] - vecBoard[iRow + 1]) == (iRow + 1) - iNavRow)
            {
                bCheck = true;
                break;
            }
        }

        if (bCheck != true)
        {
            if (Recursive_30242(iRow + 1) == true)
                return true;
        }
    }
    else
    {
        for (int iIndex = 0; iIndex < iNumRowCol; ++iIndex)
        {
            bool bCheck = { false };

            if (setBanned.find(iIndex) != setBanned.end())
                continue;

            for (int iNavRow = 0; iNavRow < iRow + 1; ++iNavRow)
            {
                if (vecBoard[iNavRow] == iIndex)
                {
                    bCheck = true;
                    break;
                }

                if (abs(vecBoard[iNavRow] - iIndex) == (iRow + 1) - iNavRow)
                {
                    bCheck = true;
                    break;
                }
            }

            if (bCheck == true)
                continue;

            vecBoard[iRow + 1] = iIndex;
            if (Recursive_30242(iRow + 1) == true)
                return true;
        }
    }

    return false;
}

int CProblem_30242::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> iNumRowCol;

    int iFlag = { }, iDigit = { };
    for (int iIndex = 0; iIndex < iNumRowCol; ++iIndex)
    {
        int iSrc = { };
        cin >> iSrc;

        if (iSrc != 0)
        {
            ++iDigit;
            iFlag += iIndex;

            setBanned.emplace(iSrc - 1);
            vecBoard.push_back(iSrc - 1);
        }
        else
        {
            vecBoard.push_back(0);
        }

        vecFixed.push_back((iSrc != 0));
    }

    if (iDigit > 0 && iFlag / iDigit > iNumRowCol / 2)
    {
        reverse(vecBoard.begin(), vecBoard.end());
        reverse(vecFixed.begin(), vecFixed.end());
        bFlag = true;
    }
    else
        bFlag = false;

    if (vecFixed[0] == true)
    {
        if (Recursive_30242(0) == true)
            return 0;
    }
    else
    {
        for (int iIndex = 0; iIndex < iNumRowCol; ++iIndex)
        {
            if (setBanned.find(iIndex) != setBanned.end())
                continue;

            vecBoard[0] = iIndex;
            if (Recursive_30242(0) == true)
                return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
