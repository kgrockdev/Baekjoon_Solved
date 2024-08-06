#include "Problem_1251.h"

#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_1251::Solve_Problem()
{
	string strWord = { };
	cin >> strWord;

	priority_queue<string, vector<string>, greater<string>> pqContainer;

	for (int iSplitIdx_A = 1; iSplitIdx_A < strWord.size(); ++iSplitIdx_A)
	{
		for (int iSplitIdx_B = iSplitIdx_A; iSplitIdx_B < strWord.size() - 1; ++iSplitIdx_B)
		{
			string strSrc_A = strWord.substr(0, iSplitIdx_A);
			string strSrc_B = strWord.substr(iSplitIdx_A, iSplitIdx_B - iSplitIdx_A + 1);
			string strSrc_C = strWord.substr(iSplitIdx_B + 1);

			reverse(strSrc_A.begin(), strSrc_A.end());
			reverse(strSrc_B.begin(), strSrc_B.end());
			reverse(strSrc_C.begin(), strSrc_C.end());

			string strComb = strSrc_A + strSrc_B + strSrc_C;
			pqContainer.emplace(strComb);
		}
	}

	cout << pqContainer.top() << '\n';

	return 0;
}