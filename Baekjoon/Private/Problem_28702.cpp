#include "Problem_28702.h"

#include <string>
#include <iostream>

using namespace std;

int CProblem_28702::Solve_Problem()
{
    string strSrc[3] = { };
    cin >> strSrc[0] >> strSrc[1] >> strSrc[2];

    int iNext = { -1 };
    bool bFind = { false };

    int iNextFind = { 0 };
    while (bFind == false)
    {
        if (strSrc[iNextFind][0] != 'F' && strSrc[iNextFind][0] != 'B')
        {
            iNext = stoi(strSrc[iNextFind]);
            iNext = iNext + 3 - iNextFind;
            bFind = true;
        }
        else
            ++iNextFind;
    }

    char chBit = 0b00;

    if (iNext % 3 == 0)
        chBit |= 0b01;

    if (iNext % 5 == 0)
        chBit |= 0b10;

    if (chBit & 0b01 && chBit & 0b10)
        cout << "FizzBuzz" << endl;
    else if (chBit & 0b01)
        cout << "Fizz" << endl;
    else if (chBit & 0b10)
        cout << "Buzz" << endl;
    else
        cout << iNext << endl;

    return 0;
}

// 3의 배수 & ! 15의 배수 : Fizz
// 5의 배수 & ! 15의 배수 : Buzz
// 
// 15의 배수 : FizzBuzz
// 
// strA가 Fizz
// strB가 FizzBuzz