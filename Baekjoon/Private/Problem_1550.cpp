#include "Problem_1550.h"

using namespace std;

#include <cmath>
#include <iostream>

int CProblem_1550::Solve_Problem()
{
	string strInput = { };
	cin >> strInput;

	unsigned long long ullRes = { };
	for (int iIndex = 0; iIndex < strInput.size(); ++iIndex)
	{
		int iSpec = { };
		iSpec = strInput[strInput.size() - iIndex - 1];

		if (iSpec >= '0' && iSpec <= '9')
			ullRes += int(iSpec - '0') * pow(16, iIndex);
		else if (iSpec >= 'A' && iSpec <= 'F')
			ullRes += int(iSpec - 'A' + 10) * pow(16, iIndex);
	}

	cout << ullRes << '\n';

	return 0;
}