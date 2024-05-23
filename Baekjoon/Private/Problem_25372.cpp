#include "Problem_25372.h"

#include <string>
#include <iostream>

using namespace std;

int CProblem_25372::Solve_Problem()
{
	int iNumTC = { };
	cin >> iNumTC;

	for (int iTC = 0; iTC < iNumTC; ++iTC)
	{
		string strSrc = { };
		cin >> strSrc;

		if (strSrc.length() >= 6 && strSrc.length() <= 9)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}


	return 0;
}
