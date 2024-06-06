#include "Problem_9349.h"

#include <iostream>

using namespace std;

int CProblem_9349::Solve_Problem()
{
	int iNumTC = { };
	cin >> iNumTC;

	for (int iTC = 0; iTC < iNumTC; ++iTC)
	{
		int iN = { }, iK = { };
		cin >> iN >> iK;

		cout << (iN - iK) / (iK - 1) << endl;
	}

	return 0;
}

// 2 - 2 : 0
// 3 - 2 : 1
// 4 - 2 : 2

// 3 - 3 : 0
// 4 - 3 : 0
// 5 - 3 : 1 B A B A B
// 6 - 3 : 1 B A B AA B
// 7 - 3 : 2 B AA B AA B
// 7 - 3 : 3 B AA B AAA B
// 9 - 3 : 3 B AAA B AAA B

// 