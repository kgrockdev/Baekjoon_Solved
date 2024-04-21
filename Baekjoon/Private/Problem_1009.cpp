#include "Problem_1009.h"

using namespace std;

#include <vector>
#include <iostream>

void CProblem_1009::Solve_Problem()
{
	int iCase = { };
	cin >> iCase;

	for (int iIndex = 0; iIndex < iCase; ++iIndex)
	{
		int iA = { }, iB = { }, iAcc = { };
		cin >> iA >> iB;

		vector<int> vecContainer;

		iAcc = 1;
		for (int iSqr = 0; iSqr < iB; ++iSqr)
		{
			iAcc = (iAcc * iA) % 10;
			if ((vecContainer.size() > 0) && (iAcc == vecContainer[0]))
				break;
			
			vecContainer.push_back(iAcc);
		}

		int iUnit = (iB - 1) % vecContainer.size();
		cout << ((vecContainer[iUnit] == 0) ? 10 : vecContainer[iUnit]) << '\n';
	}
}
