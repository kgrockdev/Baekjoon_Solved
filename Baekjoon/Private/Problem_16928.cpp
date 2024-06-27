#include "Problem_16928.h"

#include <iostream>
#include <unordered_map>

using namespace std;

int CProblem_16928::Solve_Problem()
{
    int arrMemo[101] = { };
    fill_n(arrMemo, 101, 101);

    int iNumLadder = { }, iNumSnake = { };
    cin >> iNumLadder >> iNumSnake;

    unordered_map<int, int> mapSnake;
    unordered_map<int, int> mapLadder;

    for (int iLadder = 0; iLadder < iNumLadder; ++iLadder)
    {
        int iSrc = { }, iDst = { };
        cin >> iSrc >> iDst;

        mapLadder.emplace(iSrc - 1, iDst - 1);
    }

    for (int iSnake = 0; iSnake < iNumSnake; ++iSnake)
    {
        int iSrc = { }, iDst = { };
        cin >> iSrc >> iDst;

        mapSnake.emplace(iSrc - 1, iDst - 1);
    }

    arrMemo[0] = 0;
    for (int iIndex = 0; iIndex < 100; ++iIndex)
    {
        int iSrc = { 101 };

        if (iIndex + 1 < 100)
        {
            if (mapLadder.find(iIndex + 1) != mapLadder.end())
            {
                arrMemo[mapLadder.find(iIndex + 1)->second] =
                    (arrMemo[mapLadder.find(iIndex + 1)->second] < arrMemo[iIndex] + 1) 
                    ? arrMemo[mapLadder.find(iIndex + 1)->second] : arrMemo[iIndex] + 1;
            }

            else if (mapSnake.find(iIndex + 1) != mapSnake.end())
            {
                if (arrMemo[mapSnake.find(iIndex + 1)->second] > arrMemo[iIndex] + 1)
                {
                    if (iSrc > mapSnake.find(iIndex + 1)->second)
                        iSrc = mapSnake.find(iIndex + 1)->second;

                    arrMemo[mapSnake.find(iIndex + 1)->second] = arrMemo[iIndex] + 1;
                }
            }
            
            else
                arrMemo[iIndex + 1] = (arrMemo[iIndex + 1] < arrMemo[iIndex] + 1) ? arrMemo[iIndex + 1] : arrMemo[iIndex] + 1;
        }

        if (iIndex + 2 < 100)
        {
            if (mapLadder.find(iIndex + 2) != mapLadder.end())
            {
                arrMemo[mapLadder.find(iIndex + 2)->second] =
                    (arrMemo[mapLadder.find(iIndex + 2)->second] < arrMemo[iIndex] + 1)
                    ? arrMemo[mapLadder.find(iIndex + 2)->second] : arrMemo[iIndex] + 1;
            }

            else if (mapSnake.find(iIndex + 2) != mapSnake.end())
            {
                if (arrMemo[mapSnake.find(iIndex + 2)->second] > arrMemo[iIndex] + 1)
                {
                    if (iSrc > mapSnake.find(iIndex + 2)->second)
                        iSrc = mapSnake.find(iIndex + 2)->second;

                    arrMemo[mapSnake.find(iIndex + 2)->second] = arrMemo[iIndex] + 1;
                }
            }

            else
                arrMemo[iIndex + 2] = (arrMemo[iIndex + 2] < arrMemo[iIndex] + 1) ? arrMemo[iIndex + 2] : arrMemo[iIndex] + 1;
        }

        if (iIndex + 3 < 100)
        {
            if (mapLadder.find(iIndex + 3) != mapLadder.end())
            {
                arrMemo[mapLadder.find(iIndex + 3)->second] =
                    (arrMemo[mapLadder.find(iIndex + 3)->second] < arrMemo[iIndex] + 1)
                    ? arrMemo[mapLadder.find(iIndex + 3)->second] : arrMemo[iIndex] + 1;
            }

            else if (mapSnake.find(iIndex + 3) != mapSnake.end())
            {
                if (arrMemo[mapSnake.find(iIndex + 3)->second] > arrMemo[iIndex] + 1)
                {
                    if (iSrc > mapSnake.find(iIndex + 3)->second)
                        iSrc = mapSnake.find(iIndex + 3)->second;

                    arrMemo[mapSnake.find(iIndex + 3)->second] = arrMemo[iIndex] + 1;
                }
            }

            else
                arrMemo[iIndex + 3] = (arrMemo[iIndex + 3] < arrMemo[iIndex] + 1) ? arrMemo[iIndex + 3] : arrMemo[iIndex] + 1;
        }

        if (iIndex + 4 < 100)
        {
            if (mapLadder.find(iIndex + 4) != mapLadder.end())
            {
                arrMemo[mapLadder.find(iIndex + 4)->second] =
                    (arrMemo[mapLadder.find(iIndex + 4)->second] < arrMemo[iIndex] + 1)
                    ? arrMemo[mapLadder.find(iIndex + 4)->second] : arrMemo[iIndex] + 1;
            }

            else if (mapSnake.find(iIndex + 4) != mapSnake.end())
            {
                if (arrMemo[mapSnake.find(iIndex + 4)->second] > arrMemo[iIndex] + 1)
                {
                    if (iSrc > mapSnake.find(iIndex + 4)->second)
                        iSrc = mapSnake.find(iIndex + 4)->second;

                    arrMemo[mapSnake.find(iIndex + 4)->second] = arrMemo[iIndex] + 1;
                }
            }

            else
                arrMemo[iIndex + 4] = (arrMemo[iIndex + 4] < arrMemo[iIndex] + 1) ? arrMemo[iIndex + 4] : arrMemo[iIndex] + 1;
        }

        if (iIndex + 5 < 100)
        {
            if (mapLadder.find(iIndex + 5) != mapLadder.end())
            {
                arrMemo[mapLadder.find(iIndex + 5)->second] =
                    (arrMemo[mapLadder.find(iIndex + 5)->second] < arrMemo[iIndex] + 1)
                    ? arrMemo[mapLadder.find(iIndex + 5)->second] : arrMemo[iIndex] + 1;
            }
            else if (mapSnake.find(iIndex + 5) != mapSnake.end())
            {
                if (arrMemo[mapSnake.find(iIndex + 5)->second] > arrMemo[iIndex] + 1)
                {
                    if (iSrc > mapSnake.find(iIndex + 5)->second)
                        iSrc = mapSnake.find(iIndex + 5)->second;

                    arrMemo[mapSnake.find(iIndex + 5)->second] = arrMemo[iIndex] + 1;
                }
            }

            else
                arrMemo[iIndex + 5] = (arrMemo[iIndex + 5] < arrMemo[iIndex] + 1) ? arrMemo[iIndex + 5] : arrMemo[iIndex] + 1;
        }

        if (iIndex + 6 < 100)
        {
            if (mapLadder.find(iIndex + 6) != mapLadder.end())
            {
                arrMemo[mapLadder.find(iIndex + 6)->second] =
                    (arrMemo[mapLadder.find(iIndex + 6)->second] < arrMemo[iIndex] + 1)
                    ? arrMemo[mapLadder.find(iIndex + 6)->second] : arrMemo[iIndex] + 1;
            }

            else if (mapSnake.find(iIndex + 6) != mapSnake.end())
            {
                if (arrMemo[mapSnake.find(iIndex + 6)->second] > arrMemo[iIndex] + 1)
                {
                    if (iSrc > mapSnake.find(iIndex + 6)->second)
                        iSrc = mapSnake.find(iIndex + 6)->second;

                    arrMemo[mapSnake.find(iIndex + 6)->second] = arrMemo[iIndex] + 1;
                }
            }

            else
                arrMemo[iIndex + 6] = (arrMemo[iIndex + 6] < arrMemo[iIndex] + 1) ? arrMemo[iIndex + 6] : arrMemo[iIndex] + 1;
        }

        if (iSrc != 101)
            iIndex = iSrc - 1;
    }

    cout << arrMemo[99] << endl;

    return 0;
}
