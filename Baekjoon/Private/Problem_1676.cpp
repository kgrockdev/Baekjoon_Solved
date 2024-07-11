#include "Problem_1676.h"

#include <iostream>

using namespace std;

int CProblem_1676::Solve_Problem()
{
	int iNum = { }, iAnswer = { };
	cin >> iNum;

	iAnswer = iNum / 5;
	iAnswer += iNum / 25;
	iAnswer += iNum / 125;

	cout << iAnswer << endl;

	return 0;
}

// 1 0
// 5 1
// 10 2
// 15 3
// 20 4
// 25 6
// 30 7
// 35 8
// 40 9
// 45 10
// 50 12
