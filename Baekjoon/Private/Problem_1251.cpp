#include "Problem_1251.h"

using namespace std;

#include <string>
#include <iostream>
#include <algorithm>

void CProblem_1251::Solve_Problem()
{
	string strTemp = { }, strWord = { }, strResWord = { };
	cin >> strWord;

	int iWordIdx = { -1 }, iDup = { 1 };

	for (int iSelChar = 0; iSelChar < 2; ++iSelChar)
	{
		strTemp = { };

		for (int iIndex = 0; iIndex < strWord.length() - (2 - iSelChar); ++iIndex)
		{
			if (iIndex == 0)
			{
				iWordIdx = iIndex;
				iDup = 1;
			}
			else
			{
				if (strWord[iIndex] = strWord[iWordIdx])
				{
					int iTempDup = { 2 };

					while (iIndex < strWord.length())
					{
						if (strWord[iIndex + 1] == strWord[iWordIdx])
						{
							iIndex++;
						}


						if (iIndex )
					}
				}
				else
				{
					if (strWord[iIndex] < strWord[iWordIdx])
						iWordIdx = iIndex;
				}
			}
		}

		reverse(strWord.begin(), strWord.end());
		for (int iIndex = 0; iIndex <= iWordIdx; ++iIndex)
		{
			strTemp.push_back(strWord.back());
			strWord.pop_back();
		}
		reverse(strWord.begin(), strWord.end());
		reverse(strTemp.begin(), strTemp.end());

		strResWord.append(strTemp);
	}

	strTemp = { };

	reverse(strWord.begin(), strWord.end());
	while (strWord.length() > 0)
	{
		strTemp.push_back(strWord.back());
		strWord.pop_back();
	}
	reverse(strTemp.begin(), strTemp.end());
	strResWord.append(strTemp);

	cout << strResWord << '\n';
}