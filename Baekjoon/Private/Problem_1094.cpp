#include "Problem_1094.h"

using namespace std;

#include <iostream>

int CProblem_1094::Solve_Problem()
{
	int iStick = { };
	cin >> iStick;

	int iBit = { 0 };
	int iDetectBit = { 64 };

	while (iDetectBit > 0)
	{
		if (iStick - iDetectBit >= 0)
		{
			iBit += 1;
			iStick -= iDetectBit;
		}

		iDetectBit = iDetectBit >> 1;
	}

	cout << iBit;

	return 0;
}
