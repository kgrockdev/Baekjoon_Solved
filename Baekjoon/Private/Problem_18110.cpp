#include "Problem_18110.h"

#include <list>
#include <cmath>
#include <iostream>

using namespace std;

int CProblem_18110::Solve_Problem()
{
	int iNum = { }, iSrc = { };
	cin >> iNum;

	list<int> lstContainer;

	for (int iIndex = 0; iIndex < iNum; ++iIndex)
	{
		cin >> iSrc;
		lstContainer.push_back(iSrc);
	}
	lstContainer.sort();

	int iTrim = floorf(lstContainer.size() * 0.15f + 0.5f);

	for (int iIndex = 0; iIndex < iTrim; ++iIndex)
	{
		lstContainer.pop_front();
		lstContainer.pop_back();
	}

	int iRes = { };
	for (auto iter : lstContainer)
		iRes += iter;

	if (lstContainer.size() == 0)
		cout << 0 << endl;
	else
		cout << (int)floorf((float)iRes / lstContainer.size() + 0.5f) << endl;

	return 0;
}
