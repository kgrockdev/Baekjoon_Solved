#include "Problem_8394.h"

#include <iostream>

using namespace std;

int CProblem_8394::Solve_Problem()
{
	int iQuery = { };
	cin >> iQuery;

	char arrContainer[10000000] = { };
	arrContainer[0] = 1;
	arrContainer[1] = 2;

	for (int iIndex = 2; iIndex < iQuery; ++iIndex)
		arrContainer[iIndex] = (arrContainer[iIndex - 1] + arrContainer[iIndex - 2]) % 10;

	cout << (int)arrContainer[iQuery - 1] << '\n';

	return 0;
}