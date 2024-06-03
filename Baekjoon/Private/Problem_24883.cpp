#include "Problem_24883.h"

#include <iostream>

using namespace std;

int CProblem_24883::Solve_Problem()
{
    char chSrc = { };
    cin >> chSrc;

    if (chSrc == 'N' || chSrc == 'n')
        cout << "Naver D2" << endl;
    else
        cout << "Naver Whale" << endl;

    return 0;
}
