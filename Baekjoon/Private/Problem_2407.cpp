#include "Problem_2407.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

std::string PrintLargeInt(__uint128_t value) {
    std::ostringstream oss;
    oss << "0x" << std::hex << std::setfill('0') << std::setw(16) << (uint64_t)(value >> 64)
        << std::setw(16) << (uint64_t)value;
    return oss.str();
}

int CProblem_2407::Solve_Problem()
{
    int iN = { }, iM = { };
    cin >> iN >> iM;

    __uint128_t ui128High = { 1 }, ui128Down = { 1 };

    for (int iIndex = (iN - iM) + 1; iIndex < iN + 1; ++iIndex)
        ui128High *= iIndex;

    for (int iIndex = 1; iIndex < iM + 1; ++iIndex)
        ui128Down *= iIndex;

    PrintLargeInt(ui128High / ui128Down);

    return 0;
}

// n! / (n-r)! r!

