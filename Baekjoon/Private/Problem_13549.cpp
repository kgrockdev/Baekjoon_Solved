#include "Problem_13549.h"

#include <list>
#include <iostream>

using namespace std;

#define INT_MAX       2147483647

int CProblem_13549::Solve_Problem()
{
	int arrContainer[100002] = { };
	fill_n(arrContainer, 100002, INT_MAX);

	int iX = { }, iY = { };
	cin >> iX >> iY;

	arrContainer[iX] = 0;

	list<int> lstBFS;
	lstBFS.push_back(iX);

	while (lstBFS.size() > 0)
	{
		int iSrc = lstBFS.front();
		lstBFS.pop_front();

		if (iSrc * 2 < 100002 &&
			arrContainer[iSrc * 2] > arrContainer[iSrc])
		{
			arrContainer[iSrc * 2] = arrContainer[iSrc];
			lstBFS.push_back(iSrc * 2);
		}

		if (iSrc > 0 &&
			arrContainer[iSrc - 1] > arrContainer[iSrc] + 1)
		{
			arrContainer[iSrc - 1] = arrContainer[iSrc] + 1;
			lstBFS.push_back(iSrc - 1);
		}

		if (iSrc < 100002 &&
			arrContainer[iSrc + 1] > arrContainer[iSrc] + 1)
		{
			arrContainer[iSrc + 1] = arrContainer[iSrc] + 1;
			lstBFS.push_back(iSrc + 1);
		}
	}

	cout << arrContainer[iY] << endl;

	return 0;
}
