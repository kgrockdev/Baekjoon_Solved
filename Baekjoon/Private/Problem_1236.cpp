#include "Problem_1236.h"

using namespace std;

#include <string>
#include <iostream>

int CProblem_1236::Solve_Problem()
{
	int iRow = { }, iCol = { };
	cin >> iRow >> iCol;

	int** ppArray = new int*[iRow];

	for (int iRowIdx = 0; iRowIdx < iRow; ++iRowIdx)
	{
		ppArray[iRowIdx] = new int[iCol];

		string strInput = { };
		cin >> strInput;

		for (int iColIdx = 0; iColIdx < iCol; ++iColIdx)
		{
			if (strInput[iColIdx] == 'X')
				ppArray[iRowIdx][iColIdx] = 1;
			else
				ppArray[iRowIdx][iColIdx] = 0;
		}
	}

	int iRowNPrt = { }, iColNPrt = { };
	for (int iRowIdx = 0; iRowIdx < iRow; ++iRowIdx)
	{
		bool bPrt = { false };
		for (int iColIdx = 0; iColIdx < iCol; ++iColIdx)
		{
			if (ppArray[iRowIdx][iColIdx] == 1)
			{
				bPrt = true;
				break;
			}
		}

		if (bPrt == false)
			iRowNPrt++;
	}
	for (int iColIdx = 0; iColIdx < iCol; ++iColIdx)
	{
		bool bPrt = { false };
		for (int iRowIdx = 0; iRowIdx < iRow; ++iRowIdx)
		{
			if (ppArray[iRowIdx][iColIdx] == 1)
			{
				bPrt = true;
				break;
			}
		}

		if (bPrt == false)
			iColNPrt++;
	}

	cout << max(iRowNPrt, iColNPrt) << endl;

	return 0;
}
