#include "Problem_1149.h"

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct tagValue1149
{
    int iRedValue = { };
    int iGreenValue = { };
    int iBlueValue = { };

    pair<int, int> Calc_First()
    {
        int iMin = min({ iRedValue, iGreenValue, iBlueValue });

        if (iMin == iRedValue)
            return { 0, iMin };
        else if (iMin == iGreenValue)
            return { 1, iMin };
        else if (iMin == iBlueValue)
            return { 2, iMin };
    }

    pair<int, int> Calc_Second()
    {
        pair<int, int> pair = Calc_First();
        if (pair.first == 0)
        {
            if (iGreenValue < iBlueValue)
                return { 1, iGreenValue };
            else
                return { 2, iBlueValue };
        }
        else if (pair.first == 1)
        {
            if (iRedValue < iBlueValue)
                return { 0, iRedValue };
            else
                return { 2, iBlueValue };
        }
        else if (pair.first == 2)
        {
            if (iRedValue < iGreenValue)
                return { 0, iRedValue };
            else
                return { 1, iGreenValue };
        }
    }
} VALUE_1149;

int CProblem_1149::Solve_Problem()
{
    int iNum = { };
    cin >> iNum;

    vector<VALUE_1149> vecValues;

    for (int iIndex = 0; iIndex < iNum; ++iIndex)
    {
        VALUE_1149 tValue = { };
        cin >> tValue.iRedValue >> tValue.iGreenValue >> tValue.iBlueValue;

        vecValues.push_back(tValue);
    }

    int iRGBIndex_1 = { vecValues[0].Calc_First().first }, iRGBIndex_2 = { vecValues[0].Calc_Second().first };
    int arrContainer[2][1000] = { };
    arrContainer[0][0] = vecValues[0].Calc_First().second;
    arrContainer[1][0] = vecValues[0].Calc_Second().second;

    for (int iIndex = 1; iIndex < iNum; ++iIndex)
    {
        pair<int, int> pairFirst = vecValues[iIndex].Calc_First();
        pair<int, int> pairSecond = vecValues[iIndex].Calc_Second();

        if (pairFirst.first != iRGBIndex_1)
        {
            iRGBIndex_1 = pairFirst.first;
            arrContainer[0][iIndex] = arrContainer[0][iIndex - 1] + pairFirst.second;
        }
        else
        {
            iRGBIndex_1 = pairSecond.first;
            arrContainer[0][iIndex] = arrContainer[0][iIndex - 1] + pairSecond.second;
        }

        if (pairFirst.first != iRGBIndex_2)
        {
            iRGBIndex_2 = pairFirst.first;
            arrContainer[1][iIndex] = arrContainer[1][iIndex - 1] + pairFirst.second;
        }
        else
        {
            iRGBIndex_2 = pairSecond.first;
            arrContainer[1][iIndex] = arrContainer[1][iIndex - 1] + pairSecond.second;
        }

        if (iRGBIndex_1 == iRGBIndex_2 && iIndex < iNum - 1)
        {
            if (arrContainer[0][iIndex] < arrContainer[1][iIndex])
                arrContainer[1][iIndex] = arrContainer[0][iIndex];
            else
                arrContainer[0][iIndex] = arrContainer[1][iIndex];

            ++iIndex;

            if (iRGBIndex_1 == 0)
            {
                iRGBIndex_1 = { 1 }, iRGBIndex_2 = { 2 };

                arrContainer[0][iIndex] = arrContainer[0][iIndex - 1] + vecValues[iIndex].iGreenValue;
                arrContainer[1][iIndex] = arrContainer[1][iIndex - 1] + vecValues[iIndex].iBlueValue;
            }
            else if (iRGBIndex_1 == 1)
            {
                iRGBIndex_1 = { 0 }, iRGBIndex_2 = { 2 };

                arrContainer[0][iIndex] = arrContainer[0][iIndex - 1] + vecValues[iIndex].iRedValue;
                arrContainer[1][iIndex] = arrContainer[1][iIndex - 1] + vecValues[iIndex].iBlueValue;
            }
            else if (iRGBIndex_1 == 2)
            {
                iRGBIndex_1 = { 0 }, iRGBIndex_2 = { 1 };

                arrContainer[0][iIndex] = arrContainer[0][iIndex - 1] + vecValues[iIndex].iRedValue;
                arrContainer[1][iIndex] = arrContainer[1][iIndex - 1] + vecValues[iIndex].iGreenValue;
            }
        }
    }

    cout << min(arrContainer[0][iNum - 1], arrContainer[1][iNum - 1]) << endl;

    return 0;
}
