#include "Problem_12851.h"

#include <list>
#include <vector>
#include <iostream>

using namespace std;

#define INT_MAX       2147483647

typedef struct tagRoute
{
	int iTime = { };
	vector<int> vecDuplicate;

	tagRoute() 
		: iTime(INT_MAX) { }
} ROUTE;

int CProblem_12851::Solve_Problem()
{
	ROUTE arrContainer[100010] = { };

	int iX = { }, iY = { };
	cin >> iX >> iY;

	arrContainer[iX].iTime = 0;

	list<int> lstBFS;
	lstBFS.push_back(iX);

	while (lstBFS.size() > 0)
	{
		int iSrc = lstBFS.front();
		lstBFS.pop_front();

		if (iSrc * 2 < 100002 &&
			arrContainer[iSrc * 2].iTime >= arrContainer[iSrc].iTime + 1)
		{
			if (arrContainer[iSrc * 2].iTime == arrContainer[iSrc].iTime + 1)
			{
				arrContainer[iSrc * 2].vecDuplicate.push_back(iSrc);
			}
			else
			{
				arrContainer[iSrc * 2] = arrContainer[iSrc];
				arrContainer[iSrc * 2].iTime += 1;

				lstBFS.push_back(iSrc * 2);
			}
		}
		
		if (iSrc > 0 &&
			arrContainer[iSrc - 1].iTime >= arrContainer[iSrc].iTime + 1)
		{
			if (arrContainer[iSrc - 1].iTime == arrContainer[iSrc].iTime + 1)
			{
				arrContainer[iSrc - 1].vecDuplicate.push_back(iSrc);
			}
			else
			{
				arrContainer[iSrc - 1] = arrContainer[iSrc];
				arrContainer[iSrc - 1].iTime += 1;

				lstBFS.push_back(iSrc - 1);
			}
		}
		
		if (iSrc < 100002 &&
			arrContainer[iSrc + 1].iTime >= arrContainer[iSrc].iTime + 1)
		{
			if (arrContainer[iSrc + 1].iTime == arrContainer[iSrc].iTime + 1)
			{
				arrContainer[iSrc + 1].vecDuplicate.push_back(iSrc);
			}
			else
			{
				arrContainer[iSrc + 1] = arrContainer[iSrc];
				arrContainer[iSrc + 1].iTime += 1;

				lstBFS.push_back(iSrc + 1);
			}
		}
	}

	cout << arrContainer[iY].iTime << endl;

	int iAnsDuplicate = { (int)arrContainer[iY].vecDuplicate.size() + 1 };

	lstBFS.clear();
	for (auto& iter : arrContainer[iY].vecDuplicate)
	{
		lstBFS.push_back(iter);
	}

	while (lstBFS.size() > 0)
	{
		int iSrc = lstBFS.front();
		lstBFS.pop_front();

		iAnsDuplicate += arrContainer[iSrc].vecDuplicate.size();

		for (auto& iter : arrContainer[iSrc].vecDuplicate)
		{
			lstBFS.push_back(iter);
		}
	}

	cout << iAnsDuplicate << endl;

    return 0;
}
