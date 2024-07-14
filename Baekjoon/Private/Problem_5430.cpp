#include "Problem_5430.h"

#include <list>
#include <string>
#include <iostream>
#include <algorithm>

#define FORWARD true
#define REVERSE true

using namespace std;

int CProblem_5430::Solve_Problem()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int iNumTC = { };
	cin >> iNumTC;

	for (int iTC = 0; iTC < iNumTC; ++iTC)
	{
		bool bDirect = { FORWARD }, bError = { false };

		string strFunc = { };
		cin >> strFunc;

		int iNumArray = { };
		cin >> iNumArray;

		list<int> lstArray;
		string strArray = { }, strSrc = { };
		cin >> strArray;

		for (auto iter : strArray)
		{
			if (iter == '[')
				continue;

			if (iter == ',' || iter == ']')
			{
				if (strSrc.size() > 0)
				{
					lstArray.push_back(stoi(strSrc));
					strSrc.clear();
					continue;
				}
			}

			strSrc.push_back(iter);
		}

		for (auto iter : strFunc)
		{
			if (iter == 'R')
			{
				bDirect = !bDirect;
			}
			else
			{
				if (lstArray.size() > 0)
				{
					if (bDirect == FORWARD)
						lstArray.pop_front();
					else
						lstArray.pop_back();
				}
				else
				{
					bError = true;
					break;
				}
			}
		}

		if (bError == true)
			cout << "error\n";
		else
		{
			cout << '[';

			if (bDirect == FORWARD)
			{
				for (auto iter : lstArray)
				{
					if (iter != lstArray.back())
						cout << iter << ',';
					else
						cout << iter;
				}
			}
			else
			{
				for (auto iter = lstArray.rbegin(); iter != lstArray.rend(); ++iter)
				{
					if (iter != --lstArray.rend())
						cout << *iter << ',';
					else
						cout << *iter;
				}
			}

			cout << "]\n";
		}
	}

	return 0;
}
